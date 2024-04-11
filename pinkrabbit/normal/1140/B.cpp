#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
int n,m,q,k;
char a[MN],b[MN],f[MN],g[MN];
int h[MN],nxt[MM],to[MM],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
int main(){int T;scanf("%d",&T);
while (T--){
	scanf("%d%s",&n,a+1);
	q=k=n+7;
	F(i,1,n)if(a[i]=='>'){q=i;break;}
	dF(i,n,1)if(a[i]=='<'){k=n-i+1;break;}
	printf("%d\n",min(q,k)-1);
}
	return 0;
}

// lg