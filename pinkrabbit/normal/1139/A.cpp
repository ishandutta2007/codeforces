#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
int n,m,q,k,Ans;
char str[MN],b[MN],f[MN],g[MN];
int h[MN],nxt[MM],to[MM],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
int main(){
	scanf("%d%s",&n,str+1);
	F(i,1,n)if(~str[i]&1)Ans+=i;
	printf("%d",Ans);
	return 0;
}