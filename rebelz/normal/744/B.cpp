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

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
vector<pii> v[2][25];
int ans[1005];
bool vis[1005];

void ask(vector<int> x){
	printf("%d\n",x.size());
	for(auto r:x) printf("%d ",r);
	printf("\n");
	fflush(stdout);
}

void build(int l,int r,int dep){
	if(l==r) return;
	int mid=(l+r)/2;
	build(l,mid,dep+1);
	build(mid+1,r,dep+1);
	v[0][dep].push_back(mp(l,mid)),v[1][dep].push_back(mp(mid+1,r));
}

int main(){
	n=readint();
	build(1,n,1);
	memset(ans,0x3f,sizeof(ans));
	for(int i=1;i<=10;i++){
		for(int t=0;t<=1;t++){
			if(!v[t][i].size()) continue;
			vector<int> qry(0);
			memset(vis,0,sizeof(vis));
			for(auto x:v[t][i]) for(int j=x.fi;j<=x.se;j++) qry.push_back(j),vis[j]=1;
			ask(qry);
			int x;
			for(int j=1;j<=n;j++){
				x=readint();
				if(!vis[j]) chkmin(ans[j],x);
			}
		}
	}
	printf("-1\n");
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}