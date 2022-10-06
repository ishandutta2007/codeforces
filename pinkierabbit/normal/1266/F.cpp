#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 500005
#define MM 1000005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
inline void ckmx(int &x,int y){x=max(x,y);}
int n;
vector<int>G[MN];
int faz[MN],len[MN],gl[MN];
void DFS0(int u,int fz){
	faz[u]=fz;
	for(auto v:G[u])if(v!=fz)DFS0(v,u),len[u]=max(len[u],len[v]+1);
}
void DFS1(int u,int fz){
	static int pre[MN],suf[MN];
	int tp=0;
	for(auto v:G[u])if(v!=fz)pre[++tp]=len[v],suf[tp]=len[v];
	pre[0]=suf[tp+1]=gl[u];
	F(i,1,tp)pre[i]=max(pre[i],pre[i-1]);
	dF(i,tp,1)suf[i]=max(suf[i],suf[i+1]);
	tp=0;
	for(auto v:G[u])if(v!=fz)++tp,gl[v]=max(pre[tp-1],suf[tp+1])+1;
	for(auto v:G[u])if(v!=fz)DFS1(v,u);
}
vector<int>Vec[MN];
vector<pii>V2[MN],tmp;
inline void PB(int xx,int yy,int aa,int bb){
	if(xx==aa)--yy;
	if(xx==bb)--yy;
	if(yy)tmp.pb({xx,yy});
}
int Ans[MN];
int main(){int x,y;
	scanf("%d",&n);
	F(i,2,n)scanf("%d%d",&x,&y),G[x].pb(y),G[y].pb(x);
	if(n==2)return puts("2 1"),0;
	if(n==3)return puts("3 2 1"),0;
	DFS0(1,0);
//	F(i,1,n)printf("%d,",len[i]);puts("");
	gl[1]=-1,DFS1(1,0);
//	F(i,1,n)printf("%d,",gl[i]);puts("");
	F(i,1,n){
		for(auto v:G[i])if(v!=faz[i])Vec[i].pb(len[v]+1);
		if(i>1)Vec[i].pb(gl[i]+1);
		sort(Vec[i].begin(),Vec[i].end(),greater<int>());
		int lst=0,cnt=0;
		for(auto x:Vec[i])if(x!=lst){if(cnt)V2[i].pb({lst,cnt});lst=x,cnt=1;}else++cnt;
		if(cnt)V2[i].pb({lst,cnt});
//		for(auto x:V2[i])printf("(%d,%d),",x.fi,x.se);puts("");
	}
	F(i,1,n){
		int sz=V2[i].size(),sum=0;
		F(j,0,sz-1){
			sum+=V2[i][j].se;
			ckmx(Ans[V2[i][j].fi*2],sum);
			ckmx(Ans[V2[i][j].fi*2-1],sum);
			if(j+1<sz)ckmx(Ans[V2[i][j+1].fi*2+1],sum+1);
		}
		ckmx(Ans[1],sum+1);
	}
	F(u,2,n){
		int p=faz[u];
		tmp.clear();
		int sz1=V2[u].size(),sz2=V2[p].size();
		int i=0,j=0;
		int AA=len[u]+1,BB=gl[u]+1;
		while(i<sz1&&j<sz2){
			if(V2[u][i].fi==V2[p][j].fi){
				PB(V2[u][i].fi,V2[u][i].se+V2[p][j].se,AA,BB);
				++i,++j;
			}else if(V2[u][i].fi>V2[p][j].fi)
				PB(V2[u][i].fi,V2[u][i].se,AA,BB),
				++i;
			else
				PB(V2[p][j].fi,V2[p][j].se,AA,BB),
				++j;
		}
		while(i<sz1)PB(V2[u][i].fi,V2[u][i].se,AA,BB),++i;
		while(j<sz2)PB(V2[p][j].fi,V2[p][j].se,AA,BB),++j;
//		printf("%d--%d\n   ",u,p);
//		for(auto x:tmp)printf("(%d,%d),",x.fi,x.se);puts("");
		int sz=tmp.size(),sum=0;
		F(j,0,sz-1){
			sum+=tmp[j].se;
			ckmx(Ans[tmp[j].fi*2],sum);
		}
	}
	ckmx(Ans[n],1),ckmx(Ans[n-1],1);
	dF(i,n-2,1)ckmx(Ans[i],Ans[i+2]);
	F(i,1,n)printf("%d ",Ans[i]);puts("");
	return 0;
}