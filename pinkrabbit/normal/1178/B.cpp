#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MN 1000006
#define MM 600005
#define ll long long
#define mod 998244353
char str[MN];
int n,b[MN],c[MN];
ll ans;
int main(){
	scanf("%s",str+1),n=strlen(str+1);
	F(i,2,n)c[i]=c[i-1]+(str[i-1]=='v'&&str[i]=='v');
	dF(i,n-1,1)b[i]=b[i+1]+(str[i]=='v'&&str[i+1]=='v');
	F(i,3,n-2)if(str[i]=='o')ans+=(ll)c[i-1]*b[i+1];
	printf("%lld\n",ans);
	return 0;
}