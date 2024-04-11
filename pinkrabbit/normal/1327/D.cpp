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
inline int qpow(int b,int e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,ans;
int a[MN],c[MN],v[MN];
vector<int> get(int x){
	if(x==1)return {1};
	vector<int>ans;
	for(int i=1;i*i<=x;++i)
		if(x%i==0)ans.push_back(i),ans.push_back(x/i);
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	return ans;
}
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d",&n),ans=n;
	F(i,1,n)scanf("%d",a+i);
	F(i,1,n)scanf("%d",c+i);
	F(i,1,n)v[i]=0;
	F(i,1,n)if(!v[i]){
		vector<int>b(1,i);
		v[i]=1;
		for(int x=a[i];x!=i;x=a[x])b.push_back(x),v[x]=1;
		int sz=b.size();
		auto d=get(sz);
//		for(int x:b)printf("%d,",x);puts("");
//		for(int x:d)printf("%d,",x);puts("");
		for(int x:d){
			int ok=0;
			F2(j,0,x){
				int o2=1;
				F2(k,1,sz/x)
					if(c[b[j+k*x]]!=c[b[j]])o2=0;
				if(o2)ok=1;
			}
			if(ok)ans=min(ans,x);
		}
	}
	printf("%d\n",ans);
}	return 0;
}