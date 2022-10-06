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
char s[MN],t[MN],w[MN];
int n,m;
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	F(i,1,n)F(j,i,n){
		if(j-i+1>m)continue;
		int k=j-(m-(j-i))+1;
		if(k<1)continue;
		int c=0;
		F(p,i,j)w[++c]=s[p];
		dF(p,j-1,k)w[++c]=s[p];
		int ok=1;
		F(p,1,m)if(w[p]!=t[p]){
			ok=0;break;
		}
		if(ok){
			puts("YES");
			goto end;
		}
	}
	puts("NO");
	end:;
}	return 0;
}