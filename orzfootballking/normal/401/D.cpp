#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int dp[1<<18][100],cnt[10];
char c[20];
int a[20],m;
signed main(){
	scanf("%s%d",c+1,&m);
	int n=strlen(c+1);
	FOR(i,1,n)a[i]=c[i]-'0';
	dp[0][0]=1;
	rep(i,0,1<<n){
		rep(j,0,m){
			if(!dp[i][j])continue;
			FILL(cnt,1);
			FOR(k,1,n){
				if((i&(1<<(k-1)))==0&&cnt[a[k]]){
					if(!i&&!a[k])continue;
					cnt[a[k]]=0;
					dp[i+(1<<(k-1))][(j*10+a[k])%m]+=dp[i][j];
				}
			}
		}
	}
	cout<<dp[(1<<n)-1][0];
	RE 0;
}