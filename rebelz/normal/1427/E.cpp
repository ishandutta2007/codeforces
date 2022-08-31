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

struct node{
	ll x,y,opt;
	node(ll x=0,ll y=0,ll opt=0):x(x),y(y),opt(opt){}
};

mt19937_64 mrand(1);
ll n;
ll b[60];
vector<node> ans;

void get(ll p){
	ll x=n,lst=0;
	for(;p;p>>=1,x<<=1){
		if(p&1){
			if(lst) ans.pb(node(lst,x,1));
			lst+=x;
		}
	}
}

void add(ll x){
	ll st=x;
	vector<int> v(0);
	for(int i=59;i>=0;i--){
		if((x>>i)&1){
			if(!b[i]){
				get(st/n);
				ll lst=st;
				for(auto r:v){
					ans.pb(node(lst,b[r],2));
					lst^=b[r];
				}
				b[i]=x;
				return;
			}
			else{
				v.pb(i);
				x^=b[i];
			}
		}
	}
}

int main(){
	n=readint();
	ll tmp=n;
	while(tmp*2<=(1ll<<60)){
		ans.pb(node(tmp,tmp,1));
		tmp<<=1;
	}
	while(1){
		ll x=mrand()%((1ll<<60)/n);
		add(x*n);
		if(b[0]) break;
	}
	printf("%d\n",ans.size());
	for(auto r:ans){
		if(r.opt==1) printf("%lld + %lld\n",r.x,r.y);
		else printf("%lld ^ %lld\n",r.x,r.y);
	}
	return 0;
}