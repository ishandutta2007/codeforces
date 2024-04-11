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
int a[MN],b[MN],f[MN],g[MN];
char s[MN];
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%s",s+1),n=strlen(s+1);
	int c=1;
	F(i,1,n)if(i==n||s[i]!=s[i+1])a[++k]=s[i]-'A',b[k]=c,c=1;else++c;
//	F(i,1,k)printf("%c%d ",a[i]+'A',b[i]);
	if(~k&1)return puts("0"),0;
	F(i,1,k/2)if(a[i]!=a[k-i+1]||b[i]+b[k-i+1]<3)return puts("0"),0;
	if(b[k/2+1]==1)return puts("0"),0;
	printf("%d\n",b[k/2+1]+1);
}	return 0;
}