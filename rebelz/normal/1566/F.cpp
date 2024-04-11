// xtqqwq
#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const ll inf=1ll<<60;
int n,m;
int a[200005];
ll d[200005][2],suf[200005];
pii b[200005];
vector<pii> vec[200005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		sort(a+1,a+n+1);
		for(int i=1;i<=m;i++) b[i].fi=readint(),b[i].se=readint();
		for(int i=0;i<=n;i++) vec[i].clear();
		for(int i=1;i<=m;i++){
			int pl=lower_bound(a+1,a+n+1,b[i].fi)-a;
			if(pl==n+1) vec[n].pb(b[i]);
			else{
				if(a[pl]>b[i].se) vec[pl-1].pb(b[i]);
			}
		}
		int mina=a[1],maxa;
		for(auto r:vec[0]) chkmin(mina,r.se);
		for(int i=1;i<=n;i++) d[i][0]=d[i][1]=1ll<<60;
		d[0][0]=a[1]-mina,d[0][1]=2ll*(a[1]-mina);
		for(int i=1;i<=n;i++){
			sort(vec[i].begin(),vec[i].end());
			if(i==n){
				maxa=a[i];
				for(auto r:vec[i]) chkmax(maxa,r.fi);
				ll ans=1ll<<60;
				chkmin(ans,d[i-1][0]+2ll*(maxa-a[i]));
				chkmin(ans,d[i-1][1]+maxa-a[i]);
				printf("%lld\n",ans);
				break;
			}
			ll res[2][2]={inf,inf,inf,inf};
			mina=a[i+1],maxa=a[i];
			for(auto r:vec[i]) chkmax(maxa,r.fi),chkmin(mina,r.se);
			for(int j=0;j<2;j++) for(int k=0;k<2;k++) chkmin(res[j][k],min(1ll*(k+1)*(a[i+1]-mina),1ll*(j+1)*(maxa-a[i])));
			if(vec[i].size()){
				for(int j=0;j<=vec[i].size();j++) suf[j]=a[i+1];
				for(int j=vec[i].size()-1;j>=0;j--) suf[j]=min(suf[j+1],(ll)vec[i][j].se);
				for(int j=0;j<vec[i].size();j++){
					for(int k=0;k<2;k++)
						for(int l=0;l<2;l++)
							chkmin(res[k][l],1ll*(k+1)*(vec[i][j].fi-a[i])+1ll*(l+1)*(a[i+1]-suf[j+1]));
				}
			}
			for(int j=0;j<2;j++) for(int k=0;k<2;k++) chkmin(d[i][k],d[i-1][j^1]+res[j][k]);
		}
	}
	return 0;
}