/**
*    author:  t0urist
*    created: 10.08.1919 11:45:14
**/

#include<bits/stdc++.h>
using namespace std;
int n;
int m;
vector<double> A;
vector<double> B;
const double EPS = 1e-12;
bool ok(double x){
	double W = m + x;
	for (int i = 0; i < n; i++){
		W -=  W/A[i];
		if (W+EPS < m)return false;
		W -= W/B[(i + 1) % n];
		if (W+EPS < m)return false;
	}
	return W+EPS >= m;
}
int main(){
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		A.push_back(a);
	}
	for (int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		B.push_back(a);
	}
	double mint = 0;
	double maxt = 2000000000;
	for (int i = 0; i < 200; i++){
		double mid = (mint + maxt) / 2.0;
		if (ok(mid)){
			maxt = mid;
		}
		else{
			mint = mid;
		}
	}
	if (mint > 1100000000){
		puts("-1");
		return 0;
	}
	printf("%.16f\n", mint);
	return 0;
}