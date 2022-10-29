#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define rep(i,s,t) for(int i=(s),__t=(t);i<__t;i++)
#define per(i,s,t) for(int i=(s)-1,__t=(t);i>=__t;i--)
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define all(x) ((x).begin(),(x).end())
#define SZ(x) ((int)(x).size())
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef pair<ll,int> pli;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const db eps=1e-10;
//head
int lowbit(int x){return x&(-x);}
ll powmod(ll x,ll k){ll res=1;for(;k;k>>=1,x=x*x%mod)if(k&1)res=res*x%mod;return res;}
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
template<class T>void Min(T &a,T b){if(a>b)a=b;}
template<class T>void Max(T &a,T b){if(a<b)a=b;}
template<class T>void add(T &a,T b){a+=b;if(a>=mod)a-=mod;}
template<class T>void rd(T &x) {
    static char c;x=0;int f=1;
    while(c=getchar(),c<48)if(c=='-')f=-1;
    do x=(x<<1)+(x<<3)+(c^48);
    while(c=getchar(),c>47);
    x*=f;
}

const int N=1e6+5;
int n;
ll ans;
int sum[27];
char str[N];
map<int,int> cnt;

int main() {
	rd(n);
	rep(i,1,n+1) {
		scanf("%s",str);
		int len=strlen(str);
		memset(sum,0,sizeof(sum));
		rep(j,0,len) sum[str[j]-'a']++;
		rep(j,0,26) sum[j]=sum[j]&1;
		int sta=0;
		rep(j,0,26) if(sum[j]&1) sta+=1<<j;
		ans+=cnt[sta];
		rep(j,0,26) {
			int now=sta;
			if(sum[j]&1) now-=1<<j;
			else now+=1<<j;
			ans+=cnt[now];
		}
		cnt[sta]++;
	}
	printf("%lld\n",ans);
	return 0;	
}