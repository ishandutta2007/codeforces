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
int n,a[56],b[56];char s[MN],t[MN];
int main(){int T;scanf("%d",&T);
while(T--){
	int o=1,oo=0,k=0;
	scanf("%d%s%s",&n,s+1,t+1);
	F(j,0,25)a[j]=b[j]=0;
	F(i,1,n)++a[s[i]-'a'],++b[t[i]-'a'];
	F(j,0,25)if(a[j]!=b[j])o=0;
	if(!o){puts("NO");continue;}
	F(j,0,25)if(a[j]>=2)oo=1;
	if(oo){puts("YES");continue;}
	F(i,1,n)F(j,i+1,n)if(s[i]<s[j])k^=1;
	F(i,1,n)F(j,i+1,n)if(t[i]<t[j])k^=1;
	puts(k?"NO":"YES");
}
	return 0;
}