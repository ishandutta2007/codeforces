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
char s[MN];
map<int,set<int>>a,b;
int ans;
void g(map<int,set<int>>&c,int x,int y){
	if(c[x].count(y))++ans;
	else c[x].insert(y),ans+=5;
}
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%s",s);
	a.clear(),b.clear();
	int x=0,y=0;
	ans=0;
	for(int j=0;s[j];++j){
		if(s[j]=='W')--x,g(a,x,y);
		if(s[j]=='E')g(a,x,y),++x;
		if(s[j]=='N')--y,g(b,x,y);
		if(s[j]=='S')g(b,x,y),++y;
	}printf("%d\n",ans);
}	return 0;
}