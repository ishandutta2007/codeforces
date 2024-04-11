#include <bits/stdc++.h>

using namespace std;

const int N = 123456;
int cnt[N];

int main(){
	int n,k;
	cin >> n >> k;
	int vi[n];
	int dist = 0;
	int l = 0;
	for(int i = 0;i<n;i++){
		cin >> vi[i];
		cnt[vi[i]]++;
		if(cnt[vi[i]]==1)dist++;
		while(dist>=k&&l<i&&cnt[vi[l]]>1){
			cnt[vi[l]]--;
			l++;
		}
		if(dist>=k){
			cout << l+1 << " " << i+1 << "\n";
			exit(0);
		}
	}
	cout << "-1 -1\n";
	return 0;
}