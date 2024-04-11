#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
int N,M,eu[MM],ev[MM],ew[MM],edel[MM],deg[MN];
vector<int>G[MN];
int Q,A1[MN],A2[MN],A3[MN];
inline void ad(int u,int v,int x){++Q,A1[Q]=u,A2[Q]=v,A3[Q]=x;}
int lef[MN],lcnt;
int del[MN];
int getany(int u,int f){
//	puts("1");
	for(auto i:G[u]){
		int v=eu[i]==u?ev[i]:eu[i];
		if(v!=f)return getany(v,u);
	}
	return u;
}
void sub(int u,int f,int x){
//	puts("2");
	for(auto i:G[u]){
		int v=eu[i]==u?ev[i]:eu[i];
		if(v!=f){ew[i]-=x,sub(v,u,x);return;}
	}
}
int main(){
	scanf("%d",&N);
	F(i,1,N-1){
		scanf("%d%d%d",&eu[i],&ev[i],&ew[i]);
		++deg[eu[i]],++deg[ev[i]];
	}M=N-1;
	F(i,1,N)if(deg[i]==2)return puts("NO"),0;
	puts("YES");
	F(i,1,N)if(deg[i]==1)lef[++lcnt]=i;
	F(i,1,lcnt-2){
		F(i,1,N)G[i].clear(),deg[i]=0;
		F(j,1,M)if(!edel[j])G[eu[j]].push_back(j),++deg[eu[j]];
		F(j,1,M)if(!edel[j])G[ev[j]].push_back(j),++deg[ev[j]];
//		F(j,1,M)if(!edel[j])printf("\t(%d-%d : %d)\n",eu[j],ev[j],ew[j]);
//		printf("%d:\n",lef[i]);
		int u=lef[i],edg=G[u][0];
		int v=eu[edg]==u?ev[edg]:eu[edg],x=ew[edg];
		edel[edg]=1,del[u]=1;
		if(deg[v]>=4){
//			puts("T1");
			int a=getany(v,u);
			ad(u,a,x);
			sub(v,u,x);
		}
		else{
//			puts("T2");
			int e1=0,e2=0;
			for(auto j:G[v])if(j!=edg){if(!e1)e1=j;else e2=j;}
			int w1=ew[e1],w2=ew[e2];
			int v1=eu[e1]==v?ev[e1]:eu[e1];
			int v2=eu[e2]==v?ev[e2]:eu[e2];
			int a1=getany(v1,v),a2=getany(v2,v);
//			printf("%d %d, %d %d\n",v1,v2,a1,a2);
			int A=(x+w1-w2)/2,B=(x-w1+w2)/2;
			ad(u,a1,A),ad(u,a2,B);
			sub(v1,v,A),sub(v2,v,B);
			del[v]=1,edel[e1]=edel[e2]=1;
			++M,eu[M]=v1,ev[M]=v2,ew[M]=w1-A;
		}
	}
	F(j,1,M)if(!edel[j])ad(eu[j],ev[j],ew[j]);
	printf("%d\n",Q);
	F(i,1,Q)printf("%d %d %d\n",A1[i],A2[i],A3[i]);
	return 0;
}