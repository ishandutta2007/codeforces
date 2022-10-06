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
	int an=99999999,ai=0;
	F(x,1,100){
		int s=0;
		F(i,1,n){
			if(a[i]<x)s+=x-1-a[i];
			if(a[i]>x)s+=a[i]-x-1;
		}
		if(s<an)an=s,ai=x;
	}
	printf("%d %d\n",ai,an);
	return 0;
}