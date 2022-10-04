#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
#define LL long long
int n,m,q,k;
int a[MN],b[MN],f[MN],p[MN];
int h[MN],nxt[MM],to[MM],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
priority_queue<int,vector<int>,greater<int> >pq;
int main(){
	scanf("%d%d",&n,&k);
	F(i,1,n)scanf("%d%d",a+i,b+i),p[i]=i;
	sort(p+1,p+n+1,[](int x,int y){return b[x]<b[y];});
	LL s=0,ans=0;
	dF(i,n,1){
		pq.push(a[p[i]]),s+=a[p[i]];
		if(pq.size()>k)s-=pq.top(),pq.pop();
		ans=max(ans,s*b[p[i]]);
	}printf("%lld\n",ans);
	return 0;
}

// lg