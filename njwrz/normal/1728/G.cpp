#include<bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define RE return
using namespace std;
const int mod=998244353;
int p[20],d,n,m,pos[200005],it[20],val[20][20],dpl[20],dpr[20],q;
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
main(){
	cin>>d>>n>>m;
	FOR(i,1,n)cin>>pos[i];
	sort(pos+1,pos+n+1);
	FOR(i,1,m)cin>>p[i];
	sort(p+1,p+m+1);
	p[m+1]=2e9;p[0]=-2e9;
	FOR(i,0,m){
		FOR(j,i+1,m+1){
			val[i][j]=1;
			FOR(k,1,n)if(pos[k]>p[i]&&pos[k]<p[j]){
				val[i][j]=val[i][j]*min({d+1,pos[k]-p[i],p[j]-pos[k]})%mod;
			}
		}
	}
	dpl[0]=1;
	FOR(i,1,m+1){
		FOR(j,0,i-1)add(dpl[i],mod-dpl[j]*val[j][i]%mod);
	}
	dpr[m+1]=1;
	for(int i=m;i>=0;i--){
		FOR(j,i+1,m+1)add(dpr[i],mod-dpr[j]*val[i][j]%mod);
	}
	cin>>q;
	FOR(_,1,q){
		int x;
		cin>>x;
		int it=0;
		FOR(i,1,m+1)if(p[i]>x){
			it=i-1;break;
		}
		int ans=0;
		FOR(i,0,it)FOR(j,it+1,m+1){
			add(ans,val[i][j]*dpl[i]%mod*dpr[j]%mod*min({d+1,x-p[i],p[j]-x})%mod);
		}
		cout<<ans<<'\n';
	}
	RE 0;
}