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
const int N=2e5+9;
const ll mod=998244353;
char s[N];
bool ans[N];
vector<pii> g[N];
int sum[N],last[N],pre[26][N];
void Set(int p,int val){
	for(int i=p;i<N;i+=lb(i))sum[i]+=val;
}
int Get(int p){
	int res=0;
	for(int i=p;i;i^=lb(i))res+=sum[i];
	return res;
} 
int main(){
	scanf("%s",s+1);
	int q;
	scanf("%d",&q);
	rep(i,0,q){
		int l,r;
		scanf("%d%d",&l,&r);
		if(l==r)ans[i]=1;
		else g[r].pb({l,i});
	}
	int n=strlen(s+1);
	rep(i,1,n+1)pre[s[i]-'a'][i]=1;
	rep(id,0,26)rep(i,1,n+1)pre[id][i]+=pre[id][i-1];
	rep(i,1,n+1){
		Set(i,1);
		if(last[s[i]]){
			Set(last[s[i]],-1);
		}
		last[s[i]]=i;
		for(auto w:g[i]){
			int tot=Get(i)-Get(w.fi-1);
			if(tot==1)ans[w.se]=0;
			else if(tot==2){
				if(s[w.fi]!=s[i])ans[w.se]=1;
				else ans[w.se]=0;
			}
			else ans[w.se]=1;
		}
	}
	rep(i,0,q){
		if(ans[i])printf("Yes\n");
		else printf("No\n");
	}
}