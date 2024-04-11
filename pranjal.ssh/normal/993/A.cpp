#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]"; cout << endl;}

struct pt {
	int x, y;
	pt(int x=0, int y=0): x(x), y(y) {}
	pt operator-(const pt& b) {return pt(x-b.x, y-b.y);}
};

int cross(pt x, pt y) {
	return y.y*x.x - y.x*x.y;
}

bool inside (pt a, vector<pt> b) {
	int ar = abs(cross(b[1]-b[0], b[2]-b[0])) + abs(cross(b[2]-b[0], b[3]-b[0]));
	FOR (i, 0, 3) ar -= abs(cross(b[i] - a, b[(i+1)%4] - a));
	return ar == 0;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	vector<pt> a(4);
	FOR (i, 0, 3) cin >> a[i].x >> a[i].y, a[i].x *= 4, a[i].y *= 4;

	vector<pt> b(4);
	FOR (i, 0, 3) cin >> b[i].x >> b[i].y, b[i].x *= 4, b[i].y *= 4;
	pt A, B;
	FOR (i, 0, 3) A.x += a[i].x, A.y += a[i].y, B.x += b[i].x, B.y += b[i].y;
	A.x /= 4, A.y /= 4, B.x /= 4, B.y /= 4;

	bool ans = inside(A, b) | inside(B, a);
	FOR (i, 0, 3) ans |= inside(a[i], b) | inside(b[i], a);	
	cout << (ans ? "YES\n" : "NO\n");



	return 0;
}