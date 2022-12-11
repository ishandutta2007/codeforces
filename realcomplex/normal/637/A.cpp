#include <bits/stdc++.h>

using namespace std;

const int S = 1e6+9;
int cnt[S];
int n,v,ix,s;

int main(){
	cin >> n;
	for(int j = 0;j<n;j++){
		cin >> s;
		cnt[s]++;
		if(cnt[s]>v){
			v = cnt[s],ix = s;
		}
	}
	cout << ix << "\n";
	return 0;
}