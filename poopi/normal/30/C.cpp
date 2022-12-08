							/* in the name of Allah */
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int n, t[1010];
int x[1010], y[1010];
double p[1010];
bool mark[1010];
double dp[1010];

bool can(int i, int j){
	double dx = x[j] - x[i];
	double dy = y[j] - y[i];
	double dt = t[j] - t[i];
	if(dt < 0 || dt * dt < dx * dx + dy * dy)
		return false;
	return true;
}

double mem(int idx){
	if(mark[idx])
		return dp[idx];
	mark[idx] = true;
	double mx = 0;
	for(int i = 0; i < n; i++){
		if(i != idx && can(idx, i))
			mx = max(mx, mem(i));
	}
	return dp[idx] = p[idx] + mx;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i] >> t[i] >> p[i];
	double mx = 0;
	for(int i = 0; i < n; i++){
		mx = max(mx, (double)mem(i));
	}
	cout.precision(7);
	cout.setf(ios::fixed | ios::showpoint);
	cout << mx << endl;
	return 0;
}