#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	ll li,s = 0;
	ll cap[n];
	for(int j = 0;j<n;j++){
		cin >> li;
		s += li;
	}	
	for(int j = 0;j<n;j++){
		cin >> cap[j];
	}
	sort(cap,cap+n);
	cout << ((s<=cap[n-1]+cap[n-2]) ? "YES\n" : "NO\n");
	return 0;
}