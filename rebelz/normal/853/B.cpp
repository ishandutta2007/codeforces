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

const int N=1000000;
int n,m,k;
ll now[100005],pl[100005],mina[100005];
vector<pii> lf[100005],rg[100005];
vector<int> vec[1000005],tv[1000005];
vector<ll> d[100005];

int main(){
	n=readint(); m=readint(); k=readint();
	int x,y,z,w;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint(); z=readint(); w=readint();
		if(y==0){
			rg[z].pb(mp(x,w));
			if(x-k-1>=0) tv[x-k].pb(z);
		}
		else lf[y].pb(mp(x,w)),vec[x].pb(y);
	}
	for(int i=1;i<=n;i++){
		sort(lf[i].begin(),lf[i].end());
		sort(rg[i].begin(),rg[i].end());
		d[i].resize(rg[i].size()+1);
		d[i][rg[i].size()]=1<<30;
		if(d[i].size()>1){
			for(int j=rg[i].size();j>=1;j--) d[i][j-1]=min(d[i][j],(ll)rg[i][j-1].se);
		}
	}
	ll tmp=0,num=n;
	for(int i=1;i<=n;i++){
		now[i]=0;
		pl[i]=lower_bound(rg[i].begin(),rg[i].end(),mp(k+1,0))-rg[i].begin();
		tmp+=d[i][pl[i]]+(1ll<<30);
		mina[i]=1<<30;
		if(pl[i]==rg[i].size()) return printf("-1\n"),0;
	}
	ll ans=1ll<<60; bool fl=0;
	for(int i=1;i<=N;i++){
		for(auto r:vec[i]){
			tmp-=d[r][pl[r]]+mina[r];
			if(mina[r]==(1<<30)) num--;
			chkmin(mina[r],(ll)lf[r][now[r]].se);
			now[r]++;
			tmp+=d[r][pl[r]]+mina[r];
		}
		for(auto r:tv[i]){
			tmp-=d[r][pl[r]]+mina[r];
			pl[r]++;
			if(pl[r]==rg[r].size()){
				fl=1;
				break;
			}
			tmp+=d[r][pl[r]]+mina[r];
		}
		if(fl) break;
		if(!num) chkmin(ans,tmp);
	}
	printf("%lld\n",(ans==1ll<<60)?-1:ans);
	return 0;
}