#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 205
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n;
char s[MN][MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	F(i,1,n)scanf("%s",s[i]+1);
	char k='0';
	if(s[1][2]==s[2][1])k=s[1][2];
	else if(s[n][n-1]==s[n-1][n])k=s[n][n-1]^1;
	int c=0;
	if(s[1][2]!=k)++c;
	if(s[2][1]!=k)++c;
	if(s[n][n-1]==k)++c;
	if(s[n-1][n]==k)++c;
	printf("%d\n",c);
	if(s[1][2]!=k)printf("1 2\n");
	if(s[2][1]!=k)printf("2 1\n");
	if(s[n][n-1]==k)printf("%d %d\n",n,n-1);
	if(s[n-1][n]==k)printf("%d %d\n",n-1,n);
}	return 0;
}