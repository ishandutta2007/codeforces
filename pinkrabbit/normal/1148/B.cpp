#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
int n,m,t1,t2,k;
int a[MN],b[MN],f[MN],g[MN];
int h[MN],nxt[MM],to[MM],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
int main(){
	scanf("%d%d%d%d%d",&n,&m,&t1,&t2,&k);
	F(i,1,n)scanf("%d",a+i);
	F(i,1,m)scanf("%d",b+i);
	if(k>=min(n,m))return puts("-1"),0;
	int ans=-1;
	F(i,1,k+1){
		int l=k-i+1;
		int p=lower_bound(b+1,b+m+1,a[i]+t1)-b;
		p+=l;
		if(p<=m){
			if(ans==-1||ans<b[p]+t2)ans=b[p]+t2;
		}else return puts("-1"),0;
	}
	printf("%d\n",ans);
	return 0;
}