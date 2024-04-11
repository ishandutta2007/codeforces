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
const int N=2e6+9;
const ll mod=998244353;
char s[110][52];
int vis[110],one,cnt,ord[N];
pii ans[110];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n+1)scanf("%s",s[i]);
	rep(i,1,n+1){
		if(vis[i])continue;
		int flag=0;
		rep(j,i+1,n+1){
			if(vis[j])continue;
			flag=1;
			rep(k,0,m){
				if(s[i][k]!=s[j][m-1-k]){
					flag=0;
					break;
				}
			}
			if(flag){
				ans[cnt++]={i,j};
				vis[i]=1;
				vis[j]=1;
			//	cout<<i<<' '<<j<<"check\n";
				break;
			}
		}
		if(!flag&&!one){
			flag=1;
			rep(k,0,m){
				if(s[i][k]!=s[i][m-1-k]){
					flag=0;
					break;
				}
			}
			if(flag)one=i;
		}
	}
	int tot=0;
//	cout<<cnt<<"cnt\n";
	rep(i,0,cnt)ord[tot++]=ans[i].fi;
	if(one)ord[tot++]=one;
	per(i,0,cnt)ord[tot++]=ans[i].se;
	printf("%d\n",tot*m);
	rep(i,0,tot)printf("%s",s[ord[i]]);
}