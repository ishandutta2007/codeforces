#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
inline int qpow(int b,ll e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,x,y,C;
int a[MN],b[MN],p[MN],ip[MN],bx[MN],c[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d%d",&n,&x,&y);
	F(i,1,n+1)b[i]=bx[i]=0;
	F(i,1,n)scanf("%d",a+i),++b[a[i]],p[i]=i;
	sort(p+1,p+n+1,[](int i,int j){return a[i]<a[j];});
	F(i,1,n)ip[p[i]]=i;
	sort(a+1,a+n+1);
	F(i,1,n+1)if(!b[i])C=i;
	priority_queue<pii>pq;
	F(i,1,n+1)if(b[i])pq.push({b[i],i});
	F(i,1,x){
		pii e=pq.top();pq.pop();
		int u=e.second;
		--b[u],pq.push({b[u],u});
		++bx[u];
	}
	vector<int>seq;
	F(i,1,n){
		if(bx[a[i]])c[i]=a[i],--bx[a[i]];
		else c[i]=0,seq.pb(a[i]);
	}
	F(i,1,n-y)seq.pb(C);
	b[C]+=n-y;
	int maxv=*max_element(b+1,b+n+2);
	if(maxv*2>n-x+n-y){puts("NO");continue;}
	puts("YES");
//	for(int x:seq)printf("%d,",x);puts("");
	rotate(seq.begin(),seq.begin()+maxv,seq.end());
//	for(int x:seq)printf("%d,",x);puts("");
	int id=0;
	F(i,1,n)if(!c[i])c[i]=seq[id++];
	F(i,1,n)printf("%d ",c[ip[i]]);
	puts("");
}	return 0;
}
// a[p[i]]=A[i]
// A: inc
// a: unord
// a[i]=A[ip[i]]