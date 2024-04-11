#include <bits/stdc++.h>
using namespace std;

using Point = complex<double>;
const int MAXN = 100005;

struct Event {
  double T, A, B;
  int id;
  Event() {}
  Event(double T, double A, double B, int id) : T(T), A(A), B(B), id(id) {}
  bool operator < (const Event &o) { return T < o.T; }
};

int N, Q;
Point P[MAXN];
double ans[MAXN];
vector<Event> events;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N >> Q;
  int low = 0;
  for (int i = 0; i < N; i++) {
    double x, y;
    cin >> x >> y;
    P[i] = Point(x, y);
    if (P[low].imag() > P[i].imag()) {
      low = i;
    }
  }
  for (int i = 0; i < Q; i++) {
    double f;
    cin >> f;
    events.push_back({f, 0, 0, i});
  }

  auto AddSegment = [&](Point p, Point q, int k) {
    if (abs(q.real() - p.real()) < 1e-9) return; // vertical line
    if (p.real() > q.real()) {
      swap(p, q);
      k *= -1;
    }
    double A = (q.imag() - p.imag()) / (q.real() - p.real());
    double B = p.imag() - A * p.real();
    events.push_back({p.real(), +k * A, +k * B, -1});
    events.push_back({q.real(), -k * A, -k * B, -1});
  };

  double area = 0;
  for (int i = 0; i < N; i++) {
    area += (conj(P[i]) * (P[(i + 1) % N])).imag();
    if (P[i].imag() < P[(i + 1) % N].imag()) {
      AddSegment(P[i], P[(i + 1) % N], -1);
    } else {
      AddSegment(P[(i + 1) % N], P[i], -1);
    }
  }
  rotate(P, P + low, P + N);
  int L = 0, R = 0;
  Point last = P[0];
  for (int i = 0; i + 1 < N; i++) {
    int nxtL = (L + 1) % N, nxtR = (R + N - 1) % N;
    Point cur;
    auto Projection = [&](Point p, Point q, Point r) {
      return Point(p.real() + (r.imag() - p.imag()) * (q.real() - p.real()) / (q.imag() - p.imag()), r.imag());
    };
    if (P[nxtL].imag() < P[nxtR].imag()) {
      cur = 0.5 * (P[nxtL] + Projection(P[R], P[nxtR], P[nxtL]));
      L = nxtL;
    } else {
      cur = 0.5 * (P[nxtR] + Projection(P[L], P[nxtL], P[nxtR]));
      R = nxtR;
    }
    AddSegment(last, cur, 2);
    last = cur;
  }
  
  area = 0.5 * abs(area);
  sort(begin(events), end(events));
  double A = 0, B = 0;
  for (auto ev : events) {
    if (ev.id >= 0) {
      ans[ev.id] = area + (0.5 * A * ev.T * ev.T + B * ev.T);
    } else {
      area -= 0.5 * ev.A * ev.T * ev.T + ev.B * ev.T;
      A += ev.A;
      B += ev.B;
    }
  }
  
  cout << fixed << setprecision(12);
  for (int i = 0; i < Q; i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}