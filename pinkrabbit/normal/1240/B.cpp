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
int n;
int a[MN],d[MN],c;
int p1[MN],p2[MN];
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n),c=0;
		F(i,1,n)scanf("%d",a+i),d[++c]=a[i];
		sort(d+1,d+c+1),c=unique(d+1,d+c+1)-d-1;
		F(i,1,n)a[i]=lower_bound(d+1,d+c+1,a[i])-d;
//		F(i,1,n)printf("%d%c",a[i]," \n"[i==n]);
		F(i,1,c)p1[i]=n,p2[i]=1;
		F(i,1,n)p1[a[i]]=min(p1[a[i]],i),p2[a[i]]=max(p2[a[i]],i);
		int mxl=1,lst=0,nl=0;
		F(i,1,c)if(lst<p1[i])mxl=max(mxl,++nl),lst=p2[i];else nl=1,lst=p2[i];
		debug("mxl=%d\n",mxl);
		printf("%d\n",c-mxl);
	}
	return 0;
}