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

const int cys=1000000007;
int n,tot;
ll a[200005],p[2000005],cnt[2000005],prm[10005];
bool fl[10005];
vector<pii> v[200005];

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

void getprime(int N){
	fl[1]=1;
	for(int i=2;i<=N;i++){
		if(!fl[i]) prm[++tot]=i;
		for(int j=1;j<=tot&&i*prm[j]<=N;j++){
			fl[i*prm[j]]=1;
			if(i%prm[j]==0) break;
		}
	}
}

int main(){
	getprime(10000);
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	sort(a+1,a+n+1); reverse(a+1,a+n+1);
	ll ans=1;
	for(int i=1;i<=n;i++){
		if(!p[a[i]]) v[i].push_back(mp(a[i],1)),p[a[i]]=1;
		else{
			int tmp=a[i]-1;
			for(int j=1;j<=tot&&prm[j]<=sqrt(tmp);j++){
				if(tmp%prm[j]==0){
					ll cnt=0;
					while(tmp%prm[j]==0) cnt++,tmp/=prm[j];
					chkmax(p[prm[j]],cnt);
					v[i].push_back(mp(prm[j],cnt));
				}
			}
			if(tmp>1){
				chkmax(p[tmp],1ll);
				v[i].push_back(mp(tmp,1));
			}
		}
	}
	for(int i=1;i<=n;i++) for(auto r:v[i]) if(r.se==p[r.fi]) cnt[r.fi]++;
	bool ff=0;
	for(int i=1;i<=n;i++){
		bool can=1;
		for(auto r:v[i]) if(r.se==p[r.fi]&&cnt[r.fi]==1) can=0;
		if(can){
			ff=1;
			break;
		}
	}
	for(int i=1;i<=2000000;i++) ans=ans*qpow(i,p[i])%cys;
	printf("%lld\n",(ans+ff)%cys);
	return 0;
}