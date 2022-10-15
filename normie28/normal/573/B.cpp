#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 5;
const int inf = 1e9 + 5;
 
int t[nax], res[nax];
 
int main() {
	int n;
	cin>>n;
	for(int i = 1; i <= n; ++i) cin>>t[i];
	int worst = 0;
	for(int i = 1; i <= n; ++i) {
		worst = min(worst, t[i]-i);
		res[i] = i + worst;
	}
	worst = n + 1;
	for(int i = n; i >= 1; --i) {
		worst = min(worst, t[i]+i);
		res[i] = min(res[i], worst-i);
	}
	int R = 0;
	for(int i = 1; i <= n; ++i)
		R = max(R, res[i]);
	cout<<R<<endl;
}