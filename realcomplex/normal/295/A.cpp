#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 123456;
ll cnt[MAXN];
ll arr[MAXN];
ll add[MAXN];

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	for(int j = 1;j<=n;j++)cin >> arr[j];
	int li[m],ri[m];ll si[m];
	for(int j = 0;j<m;j++)
		cin >> li[j] >> ri[j] >> si[j];
	int il,ir;
	for(int i = 0;i<k;i++){
		cin >> il >> ir;
		il--;
		ir--;
		cnt[il]++;
		cnt[ir+1]--;
	}
	for(int j = 0;j<m;j++){
		if(j>0)cnt[j]+=cnt[j-1];
		add[li[j]]+=cnt[j]*si[j];
		add[ri[j]+1]-=cnt[j]*si[j];
	}
	for(int i = 1;i<=n;i++)add[i]+=add[i-1];
	for(int i = 1;i<=n;i++)cout << add[i]+arr[i] << " ";
	return 0;
}