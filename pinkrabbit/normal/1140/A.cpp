#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
int n,m,q,k;
int a[MN],b[MN],f[MN],g[MN];
int h[MN],nxt[MM],to[MM],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	int Ans = 0, mx = 0;
	F(i,1,n) {
		mx = max(mx, a[i]);
		if (mx == i) ++Ans;
	} printf("%d\n", Ans);
	return 0;
}

// lg