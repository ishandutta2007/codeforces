#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)

int n,m,k;
int S[300001],T[300001],d[300001];
int que[300001],l=1,r;
int no[300001];
int Ans[300001];

set<int> E[300001];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	F(i,1,m) scanf("%d%d",S+i,T+i), E[S[i]].insert(T[i]), E[T[i]].insert(S[i]), ++d[S[i]], ++d[T[i]];
	F(i,1,n) if(d[i]<k){
		que[++r]=i;
		no[i]=1;
	}
	int ans=n;
	dF(i,m,1){
		while(l<=r){
			int u=que[l++];
			--ans;
			for(int j:E[u]){
				if(E[j].find(u)==E[j].end()) continue;
				E[j].erase(u);
				if((--d[j])<k&&!no[j]) que[++r]=j, no[j]=1;
			}
		}
		Ans[i]=ans;
		int u=S[i], v=T[i];
		if(E[u].find(v)!=E[u].end()){
			E[u].erase(v);
			if((--d[u])<k&&!no[u]) que[++r]=u, no[u]=1;
		}
		if(E[v].find(u)!=E[v].end()){
			E[v].erase(u);
			if((--d[v])<k&&!no[v])
				que[++r]=v, no[v]=1;
		}
	}
	F(i,1,m) printf("%d\n",Ans[i]);
	return 0;
}