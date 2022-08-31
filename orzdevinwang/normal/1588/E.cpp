#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 3007, M = 114514;
const double pi = acos (-1);
int n;
double R ;
struct vec {
	double x, y;
	inline vec (double xx = 0, double yy = 0) { x = xx, y = yy; }
	inline double len () { 
		return sqrt(x * x + y * y); 
	}
	inline double angle () { 
		return atan2 (x, y); 
	} 
	inline vec rot (double alpha) {
		return vec(cos(alpha) * x - sin(alpha) * y, sin(alpha) * x + cos(alpha) * y);
	}
} a[N];
inline vec operator + (const vec &aa, const vec &bb) { 
	return vec (aa.x + bb.x, aa.y + bb.y); 
}
inline vec operator - (const vec &aa, const vec &bb) { 
	return vec (aa.x - bb.x, aa.y - bb.y); 
}
inline vec operator * (const vec &aa, const double &bb) { 
	return vec (aa.x * bb, aa.y * bb); 
}
inline vec operator / (const vec &aa, const double &bb) { 
	return vec (aa.x / bb, aa.y / bb); 
}
double cro(vec aa, vec bb) { 
	return aa.x * bb.y - aa.y * bb.x; 
}
double dot(vec aa, vec bb) {
	return aa.x * bb.x + aa.y * bb.y;
}
bool can[N][N];
pair < double, int > sa[M];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n >> R;
	L(i, 1, n) cin >> a[i].x >> a[i].y;
	L(i, 1, n) {
//		cout << "Now is " << i << '\n';
		int now = 0, tp = 0;
		L(j, 1, n) if(i != j) {
			vec delt = a[j] - a[i];
			double Len = delt.len ();
//			cout << "j = " <<  j << '\n';
			double ang = delt.angle ();
			sa[++tp] = {ang, j}; 
			if(Len <= R) continue;
			double mk = asin(R / delt.len());
			double l = ang - mk, r = ang + mk;
			if(l < -pi) l += pi * 2;
			if(r >= pi) r -= pi * 2;
			if(l <= r) now += 1;
//			cout << l << ' ' << r << '\n';
			sa[++tp] = {l, -1};
			sa[++tp] = {r, -2}; 
		}
		sort (sa + 1, sa + tp + 1);
		L(j, 1, tp) {
			if(sa[j].second > 0) can[i][sa[j].second] = !now; 
				//, cout << i << ' ' << sa[j].second << " : " << now << '\n';
			else now += sa[j].second == -1 ? -1 : 1;
		} 
//		cout <<'\n';
	}
	int ret = 0;
	L(i, 1, n) 
		L(j, i + 1, n) 
			if(can[i][j] && can[j][i]) 
				ret += 1;
	cout << ret << '\n'; 
	return 0;
}