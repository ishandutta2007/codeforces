#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n,q;
	cin >> n >> q;
	ll arr[n+1];
	ll cnt[n+1];
	arr[0] = 0;
	for(int j = 0;j<=n;j++)cnt[j]=0;
	for(int i = 1;i<=n;i++)cin >> arr[i];
	sort(arr,arr+n+1);
	int a,b;
	for(int j = 0;j<q;j++){
		cin >> a >> b;
		cnt[a]++;
		cnt[b+1]--;
	}
	for(int i = 1;i<=n;i++)cnt[i]+=cnt[i-1];
	sort(cnt,cnt+n+1);
	ll ans = 0;
	for(int i = n;i>0;i--){
		ans += cnt[i]*arr[i];
	}
	cout << ans;
	return 0;
}