#include <bits/stdc++.h>

using namespace std;
const int k=200002, c=1000002;
vector<int> a, b, result;
int n, x, y, q;
bool v[c];
vector<int> oszt[c];

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}
void multiply() {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    result.resize(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    for (int i=c-2; i>=1; i-=2) {
        for (int j=i; j<c; j+=i) {
            oszt[j].push_back(i);
        }
    }
    cin >> n >> x >> y;
    a.resize(x+1), b.resize(x+1);
    for (int i=0; i<=n; i++) {
        int ert; cin >> ert;
        a[ert]=1, b[x-ert]=1;
    }
    multiply();
    for (int i=x+1; i<result.size(); i++) {
        if (result[i]) {
            v[2*(i-x+y)]=1;
        }
    }
    cin >> q;
    for (int i=1; i<=q; i++) {
        int ert; cin >> ert;
        bool jo=0;
        for (int j:oszt[ert]) {
            if (!jo && v[j]) {
                cout << j << " ";
                jo=1;
            }
        }
        if (!jo) {
            cout << -1 << " ";
        }
    }
    return 0;
}