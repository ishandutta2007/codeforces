#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
int dp[510][510],len[510];
void upd(int &a,int b){
	if(a>b)a=b;
} 
int main(){
	int n;
	scanf("%d",&n);
	rep(i,1,n+1)scanf("%d",&dp[i][0]);
	rep(i,0,510)len[i]=1000; 
	rep(mask,1,n+1){
		rep(i,1,n+1){
			if(i+mask>n)break;
			int tot=mask+1;
			rep(j,1,tot){
				int k=tot-j;
				if(dp[i][j-1]&&dp[i+j][k-1]&&dp[i][j-1]==dp[i+j][k-1]){
					dp[i][mask]=dp[i][j-1]+1;
					break;
				}
			}
		}
	}
	len[1]=0;
	rep(i,1,n+1){
		rep(mask,0,n+1){
			if(dp[i][mask])upd(len[i+mask+1],len[i]+1);
		}
	}
	printf("%d",len[n+1]);
}