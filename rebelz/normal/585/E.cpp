#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int N=10000000,cys=1000000007;
int n,tot,maxa,ans=0;
bool fl[10000005];
int mn[10000005],af[10000005],prm[1000005],a[500005],cnt[10000005],pw[10000005],scnt[10000005];
vector<int> all,dv;
vector<pii> tmp;

ll mod(ll x){return x>=cys?x-cys:x;}

void getprime(){
	fl[1]=true;
	for(int i=2;i<=N;i++){
		if(!fl[i]) mn[i]=i,af[i]=1,prm[++tot]=i;
		for(int j=1;j<=tot&&i*prm[j]<=N;j++){
			fl[i*prm[j]]=true,mn[i*prm[j]]=prm[j];
			if(i%prm[j]==0){
				af[i*prm[j]]=af[i];
				break;
			}
			af[i*prm[j]]=i;
		}
	}
}

void dfs(int u,int now){
	if(u==tmp.size()) return (void)(dv.push_back(now));
	for(int i=0;i<=tmp[u].se;i++){
		dfs(u+1,now);
		now*=tmp[u].fi;
	}
}

void getdiv(int x){
	tmp.clear();
	while(x>1){
		if(!tmp.empty()&&mn[x]==tmp[tmp.size()-1].fi) tmp[tmp.size()-1].se++;
		else tmp.push_back(mp(mn[x],1));
		x/=mn[x];
	}
	dfs(0,1);
}

int main(){
	getprime();
	n=readint();
	for(int i=1;i<=n;i++){
		a[i]=readint();
		maxa=max(maxa,a[i]);
		dv.clear();
		getdiv(a[i]);
		for(auto x:dv) cnt[x]++;
	}
	pw[0]=1;
	for(int i=1;i<=maxa;i++) pw[i]=mod(pw[i-1]<<1);
	for(int i=1;i<=maxa;i++) scnt[i]=pw[cnt[i]]-1;
	for(int i=maxa;i>=1;i--) for(int j=i<<1;j<=maxa;j+=i) scnt[i]=mod(scnt[i]+cys-scnt[j]);
	int m,lst,fl,res;
	for(int i=2;i<=maxa;i++){
		if(!scnt[i]) continue;
		all.clear();
		for(int j=i;j>1;j=af[j]) all.push_back(mn[j]);
		m=all.size();
		res=0;
		for(int j=0;j<(1<<m);j++){
			lst=1,fl=1;
			for(int k=0;k<m;k++) if((j>>k)&1) lst*=all[k],fl*=-1;
			fl=fl<0?cys-1:fl;
			res=mod(res+1ll*fl*cnt[lst]%cys);
		}
		ans=mod(ans+1ll*res*scnt[i]%cys);
	}
	cout<<ans<<endl;
	return 0;
}