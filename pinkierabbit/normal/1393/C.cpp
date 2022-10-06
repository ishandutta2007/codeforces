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
int n,a[MN],b[MN],t[MN];
inline bool check(int dis){
//	printf("dis=%d : ",dis);
	priority_queue<pii>pq;
	F(i,1,n)b[i]=0;
	F(i,1,n)++b[a[i]];
	F(i,1,n)t[i]=0;
	F(i,1,n)if(b[i])pq.push({b[i],i});
	F(i,1,n){
		if(t[i])pq.push({b[t[i]],t[i]});
		if(pq.empty())return 0;
		pii p=pq.top();pq.pop();
		int c=p.se;
//		printf("%d,",c);
		if(--b[c])t[i+dis]=c;
	}
	return 1;
}
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	int lb=1,rb=n-1,mid,ans=-1;
	while(lb<=rb){
		mid=(lb+rb)/2;
		if(check(mid))ans=mid,lb=mid+1;
		else rb=mid-1;
//		puts("");
	}
	printf("%d\n",ans-1);
}	return 0;
}