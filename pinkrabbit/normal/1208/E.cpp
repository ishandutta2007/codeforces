#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1000005
#define ll long long
int n,w;
int len[MN];
vector<int>A[MN];
ll s[MN],sd[MN];
int main(){
	scanf("%d%d",&n,&w);
	F(i,1,n){
		scanf("%d",len+i);
		A[i].resize(len[i]+1);
		F(j,1,len[i])scanf("%d",&A[i][j]);
	}
	F(i,1,n){
		if(len[i]*2<=w){
			int mx=0;
			F(j,1,len[i])mx=max(mx,A[i][j]),s[j]+=mx;
			mx=0;
			F(j,1,len[i])mx=max(mx,A[i][len[i]-j+1]),s[w-j+1]+=mx;
			sd[len[i]+1]+=mx,sd[w-len[i]+1]-=mx;
			continue;
		}
		A[i].resize(w+1);
		F(j,len[i]+1,w)A[i][j]=0;
		A[i][0]=0;
		int dis=w-len[i]+1;
		static int que[MN];
		int l,r;
		que[l=r=1]=0;
		F(j,1,w){
			while(l<=r&&A[i][que[r]]<A[i][j])--r;
			que[++r]=j;
			if(que[l]<=j-dis)++l;
//			printf("(i,j)=(%d,%d):%d,%d\n",i,j,que[l],A[i][que[l]]);
			s[j]+=A[i][que[l]];
		}
	}
	F(i,1,w)sd[i]+=sd[i-1];
	F(i,1,w)printf("%lld ",s[i]+sd[i]);
	return 0;
}