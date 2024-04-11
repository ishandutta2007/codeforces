#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
#define double long double 
using namespace std;
const int N = 1e5 + 7;
double a, b, c, xa, ya, xb, yb;
double dis (double xa, double ya, double xb, double yb) {
	return sqrt ((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout.precision(12), cout << fixed;
	cin >> a >> b >> c;
	cin >> xa >> ya >> xb >> yb;
	if(a == 0 || b == 0) return cout << abs(xa - xb) + abs (ya - yb) << '\n', 0;
	// ax + by + c = 0
	double lx = (- c - b * ya) / a, ly = (- c - a * xa) / b;
	double apx, apy, bpx, bpy;
//	cout << lx << ' ' << ly << '\n';
	if(min(xa, xb) <= lx && lx <= max(xa, xb)) apx = lx, apy = ya;
	else if(min(ya, yb) <= ly && ly <= max(ya, yb)) apx = xa, apy = ly;
	else return cout << abs(xa - xb) + abs (ya - yb) <<  '\n', 0;
	
	lx = (- c - b * yb) / a, ly = (- c - a * xb) / b;
	if(min(xa, xb) <= lx && lx <= max(xa, xb)) bpx = lx, bpy = yb;
	else if(min(ya, yb) <= ly && ly <= max(ya, yb)) bpx = xb, bpy = ly;
	else return cout << abs(xa - xb) + abs (ya - yb) << '\n', 0;
	
	cout << min(dis(xa, ya, apx, apy) + dis(xb, yb, bpx, bpy) + dis(apx, apy, bpx, bpy), 
	abs(xa - xb) + abs (ya - yb)) << '\n';
	return 0; 
}