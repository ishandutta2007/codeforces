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
int n;char s[MN];int a[MN],c;
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%s",s+1),n=strlen(s+1),c=0;
	F(i,1,n)a[i]=0;
	F(i,1,n)if(s[i]=='o'){
		int _1=0,_2=0;
		if(i>=3&&s[i-2]=='t'&&s[i-1]=='w')_2=1;
		if(i<=n-2&&s[i+1]=='n'&&s[i+2]=='e')_1=1;
		if(_1&&(i>=2&&s[i-1]=='o'))a[i+1]=1;
		else if(_2&&(i<=n-1&&s[i+1]=='o'))a[i-1]=1;
		else if(_1||_2)a[i]=1;
	}
	F(i,1,n)if(a[i])++c;
	printf("%d\n",c);
	F(i,1,n)if(a[i])printf("%d ",i);puts("");
}	return 0;
}