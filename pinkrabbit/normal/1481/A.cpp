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
int x,y,n;
char s[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d%s",&x,&y,s+1),n=strlen(s+1);
	int a=0,b=0,c=0,d=0;
	F(i,1,n){
		if(s[i]=='L')++a;
		if(s[i]=='R')++b;
		if(s[i]=='D')++c;
		if(s[i]=='U')++d;
	}
	int okx=x<0?a>=-x:b>=x;
	int oky=y<0?c>=-y:d>=y;
	puts(okx&&oky?"YES":"NO");
}	return 0;
}