#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 5005
#define MM 5005
#define ll long long
#define mod 1000000007
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,m;
int s[MN],f[MM],h[MM],len[MN];
vector<int>v[MN],g[MN];
int sl[MM],sr[MM],l[MN];
int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n)v[i].pb(0),g[i].pb(0);
	F(i,1,n)scanf("%d",s+i),v[s[i]].pb(i);
	F(i,1,n)len[i]=v[i].size()-1;
	F(i,1,m)scanf("%d%d",f+i,h+i);
	F(i,1,m){
		if(len[f[i]]<h[i])sl[i]=sr[i]=-1;
		else sl[i]=v[f[i]][h[i]],sr[i]=v[f[i]][len[f[i]]-h[i]+1];
//		printf("%d %d\n",sl[i],sr[i]);
		if(sl[i]!=-1)g[f[i]].pb(i);
	}
	F(i,1,n)sort(g[i].begin()+1,g[i].end(),[](int a,int b){return sl[a]<sl[b];}),l[i]=g[i].size()-1;
//	F(i,1,n){
//		printf("%d:\n  ",i);
//		F(j,1,l[i])printf("%d,",sl[g[i][j]]);printf("\n  ");
//		dF(j,l[i],1)printf("%d,",sr[g[i][j]]);puts("");
//	}
	int ansc=0,ansx=0;
	F(idx,0,n){
//		printf("idx=%d\n",idx);
		int ok=idx?0:1;
		int val=0;
		int dp=1;
		F(i,1,n){
			int th=0,idj=0;
			F(j,1,l[i])if(g[i][j][sl]==idx)ok=th=1,idj=j;
			int num,prd;
			if(th){
				int cnt=0;
				F(j,1,l[i])if(j!=idj&&g[i][j][sr]>idx)++cnt;
				if(cnt)num=2,prd=cnt;
				else num=1,prd=1;
			}else{
				int cl=0,cr=0;
				F(j,1,l[i])if(g[i][j][sl]<=idx)++cl;
				F(j,1,l[i])if(g[i][j][sr]>idx)++cr;
				if(!cl&&!cr)num=0,prd=1;
				else if(!cl||!cr)num=1,prd=cl+cr;
				else if(cl==1&&cr==1)num=1,prd=2;
				else num=2,prd=min(cl,cr)*(max(cl,cr)-1);
			}
//			printf("(%d, %d, %d) th = %d\n", i, num, prd, th);
			val+=num;
			dp=(ll)dp*prd%mod;
		}
		if(!ok)continue;
		if(val>ansc)ansc=val,ansx=0;
		if(val==ansc)ansx=(ansx+dp)%mod;
	}
	printf("%d %d\n",ansc,ansx);
	return 0;
}