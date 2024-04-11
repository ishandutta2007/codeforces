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
int n;char s[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%s",s+1),n=strlen(s+1);
	int sx=0,sy=0;
	F(i,1,n){
		if(s[i]=='L')--sx;
		if(s[i]=='R')++sx;
		if(s[i]=='D')--sy;
		if(s[i]=='U')++sy;
		
		if(sx!=0||sy!=0){
			int x=0,y=0;
			F(j,1,n){
				if(s[j]=='L')--x;
				if(s[j]=='R')++x;
				if(s[j]=='D')--y;
				if(s[j]=='U')++y;
				if(x==sx&&y==sy){
					if(s[j]=='L')++x;
					if(s[j]=='R')--x;
					if(s[j]=='D')++y;
					if(s[j]=='U')--y;
				}
			}
			if(x==0&&y==0){
				printf("%d %d\n",sx,sy);
				goto end;
			}
		}
	}
	puts("0 0");
	end:;
}	return 0;
}