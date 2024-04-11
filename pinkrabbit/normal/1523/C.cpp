#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,a[MN],d[MN];
vector<int> b[MN],s[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	F(i,1,n)b[i].clear(),d[i]=0;
	d[0]=1;
	s[1]={1};
	b[1].pb(1);
	F(i,2,n){
		if(a[i]==1)s[i]=s[i-1],s[i].pb(1);
		else{
			int c=0;
			while(d[c])
				c=b[a[i]-1].back(),
				b[a[i]-1].pop_back();
			F(k,c,i-1)d[k]=1;
			s[i]=s[c];
			++s[i].back();
		}
		b[a[i]].pb(i);
	}
	F(i,1,n){
		int sz=s[i].size();
		F(j,0,sz-1)
			printf("%d%c",s[i][j],".\n"[j==sz-1]);
	}
}	return 0;
}