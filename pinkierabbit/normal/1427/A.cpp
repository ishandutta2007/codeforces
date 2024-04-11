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
int n,a[MN],s;
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d",&n),s=0;
	F(i,1,n)scanf("%d",a+i),s+=a[i];
	if(!s){puts("NO");continue;}
	puts("YES");
	sort(a+1,a+n+1);
	if(s>0)reverse(a+1,a+n+1);
	F(i,1,n)printf("%d%c",a[i]," \n"[i==n]);
}	return 0;
}