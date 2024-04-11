#include <bits/stdc++.h>

using namespace std;

int cnt[305];

int main(){
	int p,n;
	cin >> p >> n;
	int k;
	for(int j = 0;j<n;j++){
		cin >> k;
		k%=p;
		cnt[k]++;
		if(cnt[k]>1){
			cout << j+1 << "\n";
			exit(0);
		}
	}
	cout << -1 << "\n";
	return 0;
}