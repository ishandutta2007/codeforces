#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 100005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,k,c;
char s[MN];
int b[MN],t;
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d%s",&n,&k,s+1),c=t=0;
	F(i,1,n)c+=s[i]=='W';
	if(k>=n-c){printf("\t\t%d\n",2*n-1);continue;}
	int lst=0;
	F(i,1,n)if(s[i]=='W'){
		if(lst&&i-lst>=2)b[++t]=i-lst-1;
		lst=i;
	}
	sort(b+1,b+t+1);
//	F(j,1,t)printf("%d,",b[j]);puts("");
	int p=0,sum=0;
	while(p<t&&sum+b[p+1]<=k)sum+=b[++p];
	printf("\t\t%d\n",2*(c+k)-(c?t+1-p:(k?1:0)));
}	return 0;
}