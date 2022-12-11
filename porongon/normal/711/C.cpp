#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define INF ((1LL<<62)-1)
using namespace std;

typedef long long ll;

int p[128][128];
int c[128];
int n,m,k;

ll dp[128][128][128];

ll f(int i, int k, int cc){
	if(k<0)return INF;
	if(dp[i][k][cc]>=0)return dp[i][k][cc];
	if(i==n){
		dp[i][k][cc]=k==0?0:INF;
	}
	else {
		if(c[i]<0){
			ll r=INF;
			fore(j,0,m){
				ll s=0;int w;
				if(j!=c[i])s=p[i][j];
				if(j==cc)w=0;
				else w=1;
				r=min(r,s+f(i+1,k-w,j));
			}
			dp[i][k][cc]=r;
		}
		else {
			int w;
			if(c[i]==cc)w=0;
			else w=1;
			dp[i][k][cc]=f(i+1,k-w,c[i]);
		}
	}
	return dp[i][k][cc];
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	fore(i,0,n)scanf("%d",c+i),c[i]--;
	fore(i,0,n)fore(j,0,m)scanf("%d",&(p[i][j]));
	memset(dp,-1,sizeof(dp));
	ll r=f(0,k,m+2);
	if(r>=INF)cout<<-1<<endl;
	else cout<<r<<endl;
	return 0;
}