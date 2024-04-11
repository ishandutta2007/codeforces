
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
const int N = 705;
const int oo = 1e9;
const int mod = 1e9+7;
 
int a[N];
vector<int> g[N];
int dp[N][N][2];
 
bool can(int l,int r,bool t){
	if(l > r)return 1;
	int &ret = dp[l][r][t];
	if(ret!=-1)return ret;
	ret = 0;
	int u;
	if(t)u = l-1;
	else u = r+1;
	int st = lower_bound(g[u].begin(),g[u].end(),l) - g[u].begin();
	int en = upper_bound(g[u].begin(),g[u].end(),r) - g[u].begin();
	for(int i=st;i<en;i++){
		int v = g[u][i];
		ret |= can(l,v-1,0) && can(v+1,r,1);
		if(ret)return ret;
	}
	return ret;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(__gcd(a[i],a[j]) != 1){
				g[i].push_back(j);
				g[j].push_back(i);
			}
	for(int i=1;i<=n;i++){
		if(can(1,i-1,0) && can(i+1,n,1)){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
}