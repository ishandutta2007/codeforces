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

const int cys=10007;
ll n,k;
vector<pll> v[10010];
vector<int> gar;

ll get2(ll x);
ll get3(ll x);

ll get1(ll x){
	if(x==0) return 0;
	if(x==1) return k*(k+1)/2;
	ll hs=x%cys;
	for(auto r:v[hs]) if(r.fi==x) return r.se;
	ll t1=get2((x-1)*k+1);
	ll t2=get1(get3(t1+k-1));
	ll res=k*(2*t1+k-1)/2;
	if(t2>=t1) res+=t1+k-t2;
	if(!v[hs].size()) gar.push_back(hs);
	v[hs].push_back(mp(x,res));
	return res;
}

ll get2(ll x){
	if(x<=k) return x;
	ll tmp=x+x/(k*k)-2;
	while(tmp-get3(tmp)<x) tmp++;
	return tmp;
}

ll get3(ll x){
	ll tmp=(x+k*k)/(k*k+1);
	if(get1(tmp)>x) tmp--;
	return tmp;
}

int main(){
	int T=readint();
	while(T--){
		n=readint(); k=readint();
		gar.clear();
		ll tmp=get3(n);
		if(get1(tmp)==n) printf("%lld\n",tmp*(k+1));
		else{
			n-=tmp;
			printf("%lld\n",(n-1)/k*(k+1)+(n-1)%k+1);
		}
		for(auto x:gar) v[x].clear();
	}
	return 0;
}