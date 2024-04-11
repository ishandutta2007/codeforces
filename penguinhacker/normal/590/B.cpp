#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

double x1, y1, x2, y2;
double v, t;
double vx, vy, wx, wy;

double sq(double a) {
	return a*a;
}
const double EPS=1e-9;
double quad(double a, double b, double c) {
	double d=sqrt(b*b-4*a*c);
	double a1=(-b+d)/(2*a);
	return a1;
	/*double a2=(-b-d)/(2*a);
	cout << a1 << ' ' << a2 << '\n';
	//assert(a1>=0||a2>=0);
	if (a1>=-EPS&&a2<0) return a1;
	if (a2>=-EPS&&a1<0) return a2;
	if (a1>=-EPS&&a1<a2) return a1;
	//assert(a2>=0&&a2<a1);
	return a2;*/
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> x1 >> y1 >> x2 >> y2, x2-=x1, y2-=y1;
	//assert(x2!=0||y2!=0);
	cin >> v >> t;
	cin >> vx >> vy >> wx >> wy;
	double need=quad(sq(v)-sq(vx)-sq(vy), 2*(x2*vx+y2*vy), -sq(x2)-sq(y2));
	cout << fixed << setprecision(13);
	if (need<=t) {cout << need; return 0;}
	x2-=t*vx, y2-=t*vy;
	//cout << x2 << ' ' << y2 << '\n';
	need=quad(sq(v)-sq(wx)-sq(wy), 2*(x2*wx+y2*wy)+2*sq(v)*t, -sq(x2)-sq(y2)+sq(v)*sq(t))+t;
	cout << need;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/