#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 2005
#define MM 600005
#define ll long long
#define mod 998244353
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,m,q,k,ans;
int a[MN],b[MN],f[MN],g[MN];
map<int,int>mmp;
int main(){
	scanf("%d",&n),ans=n;
	F(i,1,n)scanf("%d",a+i);
	F(i,1,n){
		if(i>1&&mmp[a[i-1]]==1)break;
		if(i>1)mmp[a[i-1]]=1;
		int k=-1;
		dF(j,n,i-1){
			if(j<n&&(mmp[a[j+1]]==1||mmp[a[j+1]]==i+1))break;
			mmp[a[j+1]]=i+1;
			k=j;
		}
//		printf("(%d %d)\n",i,k);
		ans=min(ans,k-i+1);
	}printf("%d\n",ans);
	return 0;
}