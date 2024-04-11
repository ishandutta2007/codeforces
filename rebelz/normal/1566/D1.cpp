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

int n,m;
int a[90005],p[90005],res[305][305];
vector<int> vec[90005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=n*m;i++) p[i]=a[i]=readint();
		sort(p+1,p+n*m+1);
		for(int i=1;i<=n*m;i++) a[i]=lower_bound(p+1,p+n*m+1,a[i])-p;
		for(int i=1;i<=n*m;i++) vec[i].clear();
		for(int i=1;i<=n*m;i++) vec[a[i]].pb(i);
		int nx=1,ny=1;
		for(int i=1;i<=n*m;i++){
			int pl=0;
			while(pl<vec[i].size()){
				if(vec[i].size()-pl>=m-ny+1){
					for(int j=pl;j<=pl+m-ny;j++) res[nx][m-j+pl]=vec[i][j];
					pl+=m-ny+1;
					nx++,ny=1;
				}
				else{
					for(int j=pl;j<vec[i].size();j++) res[nx][ny+vec[i].size()-j-1]=vec[i][j];
					ny+=vec[i].size()-pl;
					pl=vec[i].size();
				}
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) for(int k=j+1;k<=m;k++) if(res[i][j]<res[i][k]) ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}