#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 20
#define MM 105
#define ll long long
#define mod 998244353
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,m,a[MN][MM];
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		F(i,1,n)F(j,1,m)scanf("%d",&a[i][j]);
		if(n<=3){
			static int stk[MN*MM];
			int tp=0;
			F(i,1,n)F(j,1,m)stk[++tp]=a[i][j];
			sort(stk+1,stk+tp+1);
			int ans=0;
			F(i,1,n)ans+=stk[tp-i+1];
			printf("%d\n",ans);
		}
		else if(n==4){
			static pii stk[MN*MM];
			int tp=0;
			F(i,1,n)F(j,1,m)stk[++tp]=pii(a[i][j],n*j+i-1);
			sort(stk+1,stk+tp+1);
			static int v[20],vv[20];
			F(i,1,n)v[i]=stk[tp-i+1].se/n;
			sort(v+1,v+n+1);
			F(i,1,n)vv[i]=v[i];
			int num=unique(vv+1,vv+n+1)-vv-1,ans=0;
			F(i,1,n)ans+=stk[tp-i+1].fi;
			if(num!=2)printf("%d\n",ans);
			else{
				if(v[2]!=v[3]){
					F(i,1,n+1)v[i]=stk[tp-i+1].se;
					if((v[1]^v[2]^v[3]^v[4])&1){
						if(v[5]/n==v[4]/n&&((v[5]^v[4])&1)==0)printf("%d\n",max(ans-stk[tp-2].fi+stk[tp-4].fi,ans-stk[tp-3].fi+stk[tp-5].fi));
						else printf("%d\n",ans-stk[tp-3].fi+stk[tp-4].fi);
					}
					else printf("%d\n",ans);
				}
				else printf("%d\n",ans);
			}
		}
	}
	return 0;
}