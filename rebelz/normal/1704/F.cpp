// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
int n,m;
char s[500005];
int sg[500005];
bool vis[500005];
ll fac[1000005],inv[1000005];

ll mod(ll x){return x>=cys?x-cys:x;}
ll C(ll x,ll y){return x<y?0:fac[x]*inv[y]%cys*inv[x-y]%cys;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int getsg(int x){
	if(x<=200) return sg[x];
	else return sg[x%34+68];
}

int main(){
	sg[0]=sg[0]=sg[1]=sg[1]=0;
	for(int i=2;i<=200;i++){
		for(int k=1;k<i;k++) vis[sg[k-1]^sg[i-k-1]]=1;
		for(int k=0;k<=i;k++){
			if(!vis[k]){
				sg[i]=k;
				break;
			}
		}
		for(int k=1;k<i;k++) vis[sg[k-1]^sg[i-k-1]]=0;
	}
	int T=readint();
	while(T--){
		n=readint();
		scanf("%s",s+1);
		int cnt[2]={0,0};
		for(int i=1;i<=n;i++){
			if(s[i]=='R') cnt[0]++;
			else cnt[1]++;
		}
		int num=1,fl=0,res=0,hv=0;
		for(int i=2;i<=n;i++){
			if(s[i]!=s[i-1]) num++;
			else res^=getsg(num),num=1;
		}
		res^=getsg(num);
		if(res){
			if(cnt[0]-cnt[1]+1>0) printf("Alice\n");
			else printf("Bob\n");
		}
		else{
			if(cnt[0]-cnt[1]>0) printf("Alice\n");
			else printf("Bob\n");
		}
	}
	return 0;
}