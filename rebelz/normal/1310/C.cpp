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

const ll inf=1000000000000000000ll;
ll n,m,k,cnt;
ll d[1005][1005],f[1005][1005],mina[1005],maxa[1005];
pll ans[1000005];
char s[1005];

void solve(vector<int> v,int l){
	if(!v.size()) return;
	vector<int> tmp[26];
	for(auto x:v) if(x+l<=n) tmp[s[x+l]-'a'].push_back(x);
	for(int i=0;i<26;i++){
		for(auto x:tmp[i]) ans[++cnt]=mp(x,x+l);
		solve(tmp[i],l+1);
	}
}

bool check(int x){
	for(int i=1;i<=n;i++) mina[i]=n+1,maxa[i]=0;
	for(int i=x;i<=cnt;i++){
		chkmin(mina[ans[i].fi],ans[i].se);
		chkmax(maxa[ans[i].fi],ans[i].se);
	}
	memset(d,0,sizeof(d));
	d[0][0]=1,f[1][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			if(mina[i]!=n+1){
				if(d[i-1][j]==-inf) d[mina[i]][j+1]=-inf;
				else if(d[mina[i]][j+1]!=-inf){
					d[mina[i]][j+1]+=d[i-1][j];
					if(d[mina[i]][j+1]>inf) d[mina[i]][j+1]=-inf;
				}
				if(d[i-1][j]==-inf) f[maxa[i]+1][j+1]=-inf;
				else if(f[maxa[i]+1][j+1]!=-inf){
					f[maxa[i]+1][j+1]+=d[i-1][j];
					if(f[maxa[i]+1][j+1]>inf) f[maxa[i]+1][j+1]=-inf;
				}
			}
		}
		for(int j=0;j<=m;j++){
			if(d[i-1][j]==-inf||f[i][j]==-inf) d[i][j]=-inf;
			else if(d[i][j]!=-inf){
				d[i][j]+=d[i-1][j]-f[i][j];
				if(d[i][j]>inf) d[i][j]=-inf;
			}
		}
	}
	if(d[n][m]==-inf||d[n][m]>=k) return true;
	else return false;
}

int main(){
	n=readint(); m=readint(); k=readint();
	scanf("%s",s+1);
	vector<int> v(0);
	for(int i=1;i<=n;i++) v.push_back(i);
	solve(v,0);
	int l=1,r=cnt,res=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) res=mid,l=mid+1;
		else r=mid-1;
	}
	for(int i=ans[res].fi;i<=ans[res].se;i++) printf("%c",s[i]);
	printf("\n");
	return 0;
}