#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,c,q;
int p[30005];
ll d[30005][5],to[30005][5][20];
vector<pll> v[30005][5];

void work(){
	n=readint(); c=readint(); q=readint();
	for(int i=1;i<=n;i++) p[i]=readint();
	for(int i=0;i<=c;i++) d[n+1][i]=1;
	for(int i=n;i>=1;i--){
		for(int j=0;j<=c;j++) d[i][j]=d[i+1][j];
		if(i<=n-1){
			for(int j=1;j<=c;j++) d[i][j]+=d[i+2][j-1];
		}
		if(i<=n-2){
			for(int j=2;j<=c;j++) d[i][j]+=d[i+3][j-2];
		}
		if(i<=n-3){
			for(int j=3;j<=c;j++) d[i][j]+=d[i+4][j-3];
		}
		if(i<=n-4){
			for(int j=4;j<=c;j++) d[i][j]+=d[i+5][j-4];
		}
		for(int j=1;j<=c;j++) if(d[i][j]>1e18) d[i][j]=1e18+1;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=c;j++){
			v[i][j].clear();
			v[i][j].pb(mp(p[i],d[i+1][j]));
			if(i<=n-1&&j>=1) v[i][j].pb(mp(p[i+1],d[i+2][j-1]));
			if(i<=n-2&&j>=2) v[i][j].pb(mp(p[i+2],d[i+3][j-2]));
			if(i<=n-3&&j>=3) v[i][j].pb(mp(p[i+3],d[i+4][j-3]));
			if(i<=n-4&&j>=4) v[i][j].pb(mp(p[i+4],d[i+5][j-4]));
			sort(v[i][j].begin(),v[i][j].end());
			ll sum=0;
			for(auto r:v[i][j]){
				if(r.fi==p[i]) to[i][j][0]=sum;
				sum+=r.se;
				if(sum>1e18) sum=1e18+1;
			}
		}
	}
	for(int k=1;k<=14;k++){
		for(int i=1;i<=n-(1<<k)+1;i++){
			for(int j=1;j<=c;j++){
				to[i][j][k]=to[i][j][k-1]+to[i+(1<<(k-1))][j][k-1];
				if(to[i][j][k]>1e18) to[i][j][k]=1e18+1;
			}
		}
	}
	ll x,y;
	while(q--){
		y=readint(); x=readint();
		if(d[1][c]<x){
			printf("-1\n");
			continue;
		}
		int ni=1,nj=c,fl=0;
		while(ni<=n){
			assert(x<=d[ni][nj]);
			for(int i=14;i>=0;i--)
				if(ni+(1<<i)<=n+1&&x>to[ni][nj][i]&&x<=to[ni][nj][i]+d[ni+(1<<i)][nj])
					x-=to[ni][nj][i],ni+=1<<i;
			if(ni>n) break;
			ll sum=0;
			for(auto r:v[ni][nj]){
				if(x<=sum+r.se){
					assert(r.fi!=p[ni]);
					if(ni<=n-1&&r.fi==p[ni+1]){
						if(y==ni) printf("%d\n",p[ni+1]),fl=1;
						if(y==ni+1) printf("%d\n",p[ni]),fl=1;
						ni+=2,nj--;
					}
					else if(ni<=n-2&&r.fi==p[ni+2]){
						if(y==ni) printf("%d\n",p[ni+2]),fl=1;
						if(y==ni+2) printf("%d\n",p[ni]),fl=1;
						ni+=3,nj-=2;
					}
					else if(ni<=n-3&&r.fi==p[ni+3]){
						if(y==ni) printf("%d\n",p[ni+3]),fl=1;
						if(y==ni+1) printf("%d\n",p[ni+2]),fl=1;
						if(y==ni+2) printf("%d\n",p[ni+1]),fl=1;
						if(y==ni+3) printf("%d\n",p[ni]),fl=1;
						ni+=4,nj-=3;
					}
					else if(ni<=n-4&&r.fi==p[ni+4]){
						if(y==ni) printf("%d\n",p[ni+4]),fl=1;
						if(y==ni+1) printf("%d\n",p[ni+3]),fl=1;
						if(y==ni+3) printf("%d\n",p[ni+1]),fl=1;
						if(y==ni+4) printf("%d\n",p[ni]),fl=1;
						ni+=5,nj-=4;
					}
					x-=sum;
					break;
				}
				sum+=r.se;
				if(fl) break;
			}
			if(fl) break;
		}
		if(!fl) printf("%d\n",p[y]);
	}
}

int main(){
	int T=readint();
	while(T--) work();
	return 0;
}