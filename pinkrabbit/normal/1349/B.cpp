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
int n,k;
int a[MN],d[MN],c;
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&k),d[c=1]=k;
	F(i,1,n)scanf("%d",a+i),d[++c]=a[i];
	sort(d+1,d+c+1),c=unique(d+1,d+c+1)-d-1;
	k=lower_bound(d+1,d+c+1,k)-d;
	F(i,1,n)a[i]=lower_bound(d+1,d+c+1,a[i])-d;
	int ok=0;
	F(i,1,n)if(a[i]==k)ok=1;
	if(!ok){puts("no");continue;}
	if(n==1){puts("yes");continue;}
	int l=0,mnd=inf;
	F(i,1,n){
		if(a[i]>=k){
			if(!l)l=i;
			else mnd=min(mnd,i-l),l=i;
		}
	}
	if(mnd<=2){puts("yes");continue;}
	puts("no");
}	return 0;
}