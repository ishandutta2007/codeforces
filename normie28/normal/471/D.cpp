#include <bits/stdc++.h>
using namespace std;
 
const int N = 400008;
const int maxi = 0x3d3d3d3d;
int d[N], k[N];
 
int kmp(int sz, int es){
	int ret = 0;
	if(!es) return sz;
	for(int i = 1, j = 0; i < sz; ++i){
		while(j && d[j] != d[i]) j = k[j - 1];
		if(d[j] == d[i]) k[i] = ++j;
		if(k[i] == es) ret++;
	}
	return ret;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, w;
	cin>>n>>w;
	for(int i = w; i < w + n; ++i)
		cin>>d[i];
	for(int i = 0; i < w; ++i)
		cin>>d[i];
	for(int i = 0; i + 1 < w + n; ++i)
		d[i] -= d[i + 1];
	d[w - 1] = maxi;
	cout << kmp(w + n - 1, w - 1) << '\n';
}