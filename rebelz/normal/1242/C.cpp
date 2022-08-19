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

int k;
ll sum[20],tmp[20],d[60000],fr[60000];
pll ans[20];
vector<int> v[20],pre[20];
map<ll,int> pl;

int main(){
	k=readint();
	int x; ll all=0;
	for(int i=1;i<=k;i++){
		x=readint();
		while(x--) v[i].push_back(readint());
		for(auto r:v[i]) pl[r]=i,sum[i]+=r;
		all+=sum[i];
	}
	if(all%k!=0) return printf("No\n"),0;
	all/=k;
	for(int i=1;i<=k;i++){
		for(auto r:v[i]){
			memset(tmp,0x3f,sizeof(tmp));
			ll nd=all-sum[i]+r,can=1;
			if(!pl.count(nd)){
				pre[i].push_back(-1);
				continue;
			}
			tmp[i]=r;
			int to=pl[nd],mns=1<<(i-1);
			if(to==i&&nd!=r){
				pre[i].push_back(-1);
				continue;
			}
			while(tmp[to]>1e9+10){
				mns+=1<<(to-1);
				tmp[to]=nd;
				nd=all-sum[to]+nd;
				if(!pl.count(nd)){
					can=0;
					break;
				}
				to=pl[nd];
				if(tmp[to]<=1e9+10&&tmp[to]!=nd) can=0;
				if(tmp[to]<=1e9+10&&to!=i) can=0;
			}
			if(!can) pre[i].push_back(-1);
			else pre[i].push_back(mns);
		}
	}
	d[0]=1;
	for(int i=1;i<(1<<k);i++){
		int now=0;
		for(int j=1;j<=k;j++) if((i>>(j-1))&1) now=j;
		for(int j=0;j<v[now].size();j++){
			if(pre[now][j]>=0){
				if(d[i-pre[now][j]]){
					d[i]=1,fr[i]=v[now][j];
					break;
				}
			}
		}
	}
	if(!d[(1<<k)-1]) printf("No\n");
	else{
		printf("Yes\n");
		int sta=(1<<k)-1;
		while(sta){
			int now=0;
			for(int j=1;j<=k;j++) if((sta>>(j-1))&1) now=j;
			ll r=fr[sta];
			memset(tmp,0x3f,sizeof(tmp));
			ll nd=all-sum[now]+r;
			tmp[now]=r;
			int to=pl[nd],mns=1<<(now-1);
			ans[to]=mp(nd,now);
			while(tmp[to]>1e9+10){
				mns+=1<<(to-1);
				tmp[to]=nd;
				nd=all-sum[to]+nd;
				ans[pl[nd]]=mp(nd,to);
				to=pl[nd];
			}
			sta-=mns;
		}
		for(int i=1;i<=k;i++) printf("%lld %lld\n",ans[i].fi,ans[i].se);
	}
	return 0;
}