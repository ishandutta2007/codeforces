#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1000005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define MV 5005
#define MP 5005
bool ip[MV];
int p[MP],pc;
int id[MV],lst[MV],g[MV],ig[MV],numi[MV],numps[MV];
void sieve(int n){
	g[1]=0,numi[1]=0;
	F(i,2,n){
		if(!ip[i])p[++pc]=i,id[i]=pc,ig[i]=g[i]=i,numi[i]=1;
		lst[i]=p[pc];
		F(j,1,pc){
			int k=p[j]*i;
			if(k>n)break;
			ip[k]=1;
			g[k]=p[j];
			ig[k]=ig[i];
			numi[k]=numi[i]+1;
			if(i%p[j]==0)break;
		}
	}
	F(i,2,n)numps[i]=numi[i]+numps[i-1];
	int mx=0;
	F(i,2,n)mx=max(mx,i-lst[i]+1);
//	printf("%d %d\n",pc,mx*numps[5000]);
}
int n,a[MN],buk[MN];
ll ans;
map<int,int>gg[530005];
vector<int>G[530005];
int num[530005],tot;
void DFS(int u){
	for(auto v:G[u])DFS(v),num[u]+=num[v];
}
void DFS1(int u){
	int mxv=0,mxs=0;
	for(auto v:G[u])if(num[v]>mxs)mxv=v,mxs=num[v];
	if(mxs*2>n)ans-=2*mxs-n,DFS1(mxv);
}
void solve(int pr){
	static int b[MN],d[MN],cnt[50];int c=0,cc=0;
	F(i,1,n)if(lst[a[i]]==pr)b[++c]=a[i];
	std::sort(b+1,b+c+1);
	F(i,1,c)d[++cc]=b[i];
	cc=std::unique(d+1,d+cc+1)-d-1;
	F(i,1,c)++cnt[std::lower_bound(d+1,d+cc+1,b[i])-d];
//	F(i,1,cc)printf("(%d,%d),",d[i],cnt[i]);puts("");
	F(i,1,cc){
		int x=d[i];
		static int stk[15605];int tp=0;
		F(y,1,x){
			int z=y;
			while(z>1)stk[++tp]=ig[z],z/=ig[z];
		}
		sort(stk+1,stk+tp+1,[](int ii,int jj){return ii>jj;});
//		F(j,1,tp)printf("%d,",stk[j]);puts("");
		int now=0;
		F(j,1,tp){
			int tmp=0;
			if(gg[now].find(stk[j])==gg[now].end())tmp=gg[now][stk[j]]=++tot,G[now].push_back(tot);
			else tmp=gg[now][stk[j]];
			now=tmp;
		}
		num[now]+=cnt[i];
	}
	DFS(0);
	DFS1(0);
}
int main(){
	sieve(5000);
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i),ans+=numps[a[i]];
	F(i,1,n)if(a[i]>1)++buk[lst[a[i]]];
	int pos=max_element(buk+1,buk+5000+1)-buk;
	if(buk[pos]*2>n)solve(pos);
	printf("%lld\n",ans);
	return 0;
}
/*
10
7 8 9 10 10 10 9 9 8 8
*/