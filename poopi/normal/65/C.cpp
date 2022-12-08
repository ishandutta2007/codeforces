							/* in the name of Allah */
#include <iostream>
#include <cmath>
using namespace std;

#define EPS 1e-9

int n;
double x[10010], y[10010], z[10010];
double px, py, pz, vp, vi;

bool gr(double a, double b){
	return a -EPS > b;
}

double dist(int i, int j){
	double dx = x[i] - x[j];
	double dy = y[i] - y[j];
	double dz = z[i] - z[j];
	return sqrt(dx * dx + dy * dy + dz * dz);
}

double calc(double xx, double yy, double zz){
	double dx = xx - px;
	double dy = yy - py;
	double dz = zz - pz;
	return sqrt(dx * dx + dy * dy + dz * dz) / vp;
}

int main(){
	cin >> n;
	for(int i = 0; i <= n; i++)
		cin >> x[i] >> y[i] >> z[i];
	cin >> vp >> vi;
	cin >> px >> py >> pz;
	int p = 0;
	double tm = 0;
	while(gr(calc(x[p], y[p], z[p]), tm)){
		if(p == n){
			cout << "NO" << endl;
			return 0;
		}
		tm += dist(p, p + 1) / vi;
		p++;
	}
	cout << "YES" << endl;
	if(p == 0){
		cout.precision(7);
		cout.setf(ios::fixed | ios::showpoint);
		cout << tm << endl;
		cout << px << ' ' << py << ' ' << pz << endl;
		return 0;
	}
	p--;
	tm -= dist(p, p + 1) / vi;
	double tot = dist(p, p + 1) / vi;
	double l = 0, r = tot;
	for(int i = 0; i < 100; i++){
		double mid = (l + r) / 2;
		double xx = x[p] + (x[p+1] - x[p]) * mid / tot;
		double yy = y[p] + (y[p+1] - y[p]) * mid / tot;
		double zz = z[p] + (z[p+1] - z[p]) * mid / tot;
		double hp = calc(xx, yy, zz);
		if(hp > tm + mid)
			l = mid;
		else r = mid;
	}
	double xx = x[p] + (x[p+1] - x[p]) * r / tot;
	double yy = y[p] + (y[p+1] - y[p]) * r / tot;
	double zz = z[p] + (z[p+1] - z[p]) * r / tot;
	cout.precision(7);
	cout.setf(ios::fixed | ios::showpoint);
	cout << tm + r << endl;
	cout << xx << ' ' << yy << ' ' << zz << endl;
	cin >> n;
	return 0;
}