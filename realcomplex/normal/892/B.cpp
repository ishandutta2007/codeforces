#include <bits/stdc++.h>

using namespace std;

const int N = 1000007;
int cnt[N];

int main(){
	int n;
	scanf("%i",&n);
	int l;
	for(int j = 1;j<=n;j++){
		scanf("%i",&l);
		l = min(l,j);
		cnt[j-l]++;
		cnt[j]--;
	}
	int ans = 0;
	for(int j = 1;j<=n;j++){
		cnt[j]+=cnt[j-1];
		if(cnt[j]==0)ans++;
	}
	printf("%i",ans);
	return 0;
}