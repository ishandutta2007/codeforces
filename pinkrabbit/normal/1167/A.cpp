#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
int n,m,q,k;
char a[MN],b[MN],f[MN],g[MN];
int h[MN],nxt[MM],to[MM],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d%s",&n,a+1);
		int x=0;
		F(i,1,n)if(a[i]=='8'){x=i;break;}
		if(!x)puts("NO");
		else if(n-x>=10)puts("YES");
		else puts("NO");
	}
	return 0;
}