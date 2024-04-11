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
#define mp make_pair
#define fi first
#define se second
int n,a,b,c,d;char s[MN],e[MN];
int main(){int t;scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d%s",&n,&a,&b,&c,s+1),d=0;
		F(i,1,n)e[i]='z';e[n+1]='\0';
		F(i,1,n){
			if(s[i]=='R'&&b)e[i]='P',--b,++d;
			if(s[i]=='P'&&c)e[i]='S',--c,++d;
			if(s[i]=='S'&&a)e[i]='R',--a,++d;
		}
		if(d*2>=n){
			F(i,1,n)if(e[i]=='z'){if(a)e[i]='R',--a;else if(b)e[i]='P',--b;else e[i]='S',--c;}
			printf("YES\n%s\n",e+1);
		}else puts("NO");
	}
	return 0;
}