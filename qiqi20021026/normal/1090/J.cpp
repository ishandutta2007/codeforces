#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define inf 1000000000
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define se second
#define mpr make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define set_it set<int>:: iterator
#define l_bd lower_bound
#define u_bd upper_bound
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) x=(x+(y))%mod
#define N 400009
using namespace std;

int m,n,f[N]; char s1[N],s2[N];
struct sam{
	int tot,last,ch[N][27],fa[N],len[N];
	int pos[N],dad[N][19],sz[N],q[N],sum[N];
	sam(){ last=tot=1; }
	void ins(int k,int c,int t){
		int p=last,np=last=++tot; pos[k]=tot;
		sz[np]=t; len[np]=len[p]+1;
		for (; p && !ch[p][c]; p=fa[p]) ch[p][c]=np;
		if (!p){ fa[np]=1; return; }
		int q=ch[p][c];
		if (len[p]+1==len[q]) fa[np]=q; else{
			int nq=++tot; len[nq]=len[p]+1;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			fa[nq]=fa[q]; fa[np]=fa[q]=nq;
			for (; p && ch[p][c]==q; p=fa[p]) ch[p][c]=nq;
		}
	}
	void solve(){
		int i,x,l;
		for (i=1; i<=tot; i++) sum[len[i]]++;
		for (i=1; i<=tot; i++) sum[i]+=sum[i-1];
		for (i=tot; i; i--) q[sum[len[i]]--]=i;
		for (l=tot; l; l--){
			i=q[l]; sz[fa[i]]+=sz[i];
		}
		for (l=1; l<=tot; l++){
			x=q[l]; dad[x][0]=fa[x];
			for (i=1; i<=18; i++) dad[x][i]=dad[dad[x][i-1]][i-1];	
		}
	}
	int calc(int x,int y){
		int i;
		for (i=18,x=pos[x]; i>=0; i--)
			if (len[dad[x][i]]>=y) x=dad[x][i];
		return sz[x];
	}
}sam;
int main(){
	scanf("%s%s",s1+1,s2+1);
	int m=strlen(s1+1),n=strlen(s2+1);
	int i;
	for (i=2; i<=m; i++) sam.ins(0,s1[i]-'a',1);
	sam.ins(0,26,0);
	for (i=1; i<=n; i++) sam.ins(i,s2[i]-'a',0);
	sam.solve();
	ll ans=(ll)m*n;
	for (i=2; i<=n; i++){
		f[i]=f[i-1];
		for (; f[i] && s2[f[i]+1]!=s2[i]; f[i]=f[f[i]]);
		f[i]+=(s2[f[i]+1]==s2[i]);	
		if (f[i]) ans-=sam.calc(i-f[i],i-f[i]);
	}
	printf("%lld\n",ans);
	return 0;
}