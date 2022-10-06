#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
int n,m,q,k,ans;
int a[MN],b[MN],f[MN],g[MN];
int h[MN],nxt[MM],to[MM],tot;
char sr[MN];
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
int main(){
	scanf("%d%d%s",&n,&k,sr+1);
	F(c,'a','z'){
		F(i,1,n)a[i]=sr[i]==c;
		int b=0,d=0;
		F(i,1,n){
			if(a[i])++b;else b=0;
			if(b==k)b=0,++d;
		}
		if(ans<d)ans=d;
	}printf("%d\n",ans);
	return 0;
}