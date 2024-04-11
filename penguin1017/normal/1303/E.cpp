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
using namespace std;
const int N=400+9;
const ll mod=998244353;
char s[N],t[N],s2[N];
int dp[N][N],pos[26][N];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		scanf("%s",t+1);
		int sl=strlen(s);
		int tl=strlen(t+1),flag=0;
		rep(i,0,26)rep(j,0,sl+2)pos[i][j]=sl;
		rep(i,0,sl)pos[s[i]-'a'][i]=i;
		rep(i,0,26)per(j,0,sl-1)pos[i][j]=min(pos[i][j],pos[i][j+1]);
		rep(len,1,tl+1){
			int m=len,n=tl-len;
			rep(i,0,m+1)rep(j,0,n+1)dp[i][j]=sl;
			dp[0][0]=-1;
			rep(i,1,m+1)dp[i][0]=min(dp[i][0],pos[t[i]-'a'][dp[i-1][0]+1]);
			rep(i,1,n+1)dp[0][i]=min(dp[0][i],pos[t[i+m]-'a'][dp[0][i-1]+1]);
			rep(i,1,m+1){
				rep(j,1,n+1){
				//	cout<<dp[i][j]<<"fir\n";
					dp[i][j]=min(dp[i][j],pos[t[i]-'a'][dp[i-1][j]+1]);
				//	cout<<dp[i][j]<<"sec\n"; 
					dp[i][j]=min(dp[i][j],pos[t[j+m]-'a'][dp[i][j-1]+1]);
			//	cout<<i<<' '<<j<<' '<<dp[i][j]<<"check\n";
				}
			}
		//	cout<<m<<' '<<n<<' '<<dp[m][n]<<"dp\n"; 
			if(dp[m][n]<sl){
				flag=1;
				break;
			}
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
}
/*
1
defi
fed
*/