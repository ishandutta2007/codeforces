#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	double a, b, m, vx, vy, vz;
	cin >> a >> b >> m >> vx >> vy >> vz;
	double t = (m / vy);
	t = -t;
	double x = vx*t + (double)(a/(double)2);
	double z = vz*t;
	double zbb = (z/b);
	ll p = floor(zbb);
	if(p & 1) {
		z = b - (z - (double)((double)p*b));
	} else {
		z = z - (double)((double)p*b);
	}
	double xba = (x/a);
	p = floor(xba);
	if(p & 1) {
		x = a - (x - (double)((double)p*a));
	} else {
		x = x - (double)((double)p*a);
	}
	cout << x << " " << z;
	print(xba);
}