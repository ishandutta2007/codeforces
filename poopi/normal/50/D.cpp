							/* in the name of Allah */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

#define EPS 1e-8
#define ex 2.7182818284590452353602874713527
int n, k, x, y;
double e;
int pnt[110][2];
double prob[110];
double dp[110][110];
bool mark[110][110];

double dis(int idx){
	double dx = pnt[idx][0] - x;
	double dy = pnt[idx][1] - y;
	return sqrt(dx * dx + dy * dy);
}
double leseq(double a, double b){
	return a - EPS < b;
}
double getexp(double r, double d){
	if(leseq(d, r))
		return 1.;
	double tmp = (1. - (d * d) / (r * r));
	return pow(ex, tmp);
}
double mem(int idx, int rem){
	if(rem == 0)
		return 1.;
	if(n - idx < rem)
		return 0.;
	if(mark[idx][rem])
		return dp[idx][rem];
	mark[idx][rem] = true;
	double &ref = dp[idx][rem];
	double t1 = mem(idx + 1, rem);
	double t2 = mem(idx + 1, rem - 1);
	ref = t1 + prob[idx] * (t2 - t1);
	return ref;
}

int main(){
	cin >> n >> k >> e;
	cin >> x >> y;
	for(int i = 0; i < n; i++)
		cin >> pnt[i][0] >> pnt[i][1];
	e /= 1000;
	double l = 0, r = 10000;
	for(int i = 0; i < 80; i++){
		double mid = (l + r) / 2.;
		for(int j = 0; j < n; j++)
			prob[j] = getexp(mid, dis(j));
		memset(mark, false, sizeof mark);
		double res = mem(0, k);
		if(leseq(1. - res, e))
			r = mid;
		else l = mid;
	}
	cout.precision(7);
	cout.setf(ios::fixed | ios::showpoint);
	cout << r << endl;
	return 0;
}