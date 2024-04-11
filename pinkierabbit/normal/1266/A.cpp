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
int n,m,q,k;
char s[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%s",s+1),n=strlen(s+1);
	int c=0,o1=0,o2=0;
	F(i,1,n)(c+=s[i]-'0')%=3;
	F(i,1,n)if(s[i]=='0')o1=1;
	F(i,1,n)if(s[i]%2==0)++o2;
	if(c)puts("cyan");
	else if(!o1)puts("cyan");
	else if(o2<2)puts("cyan");
	else puts("red");
}	return 0;
}