#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=555555,mod=998244353;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,m,p[maxn],rk[maxn],tmp[maxn],at;
string s;
inline bool cmp1(int x,int y){
	return s[x]<s[y];
}
inline bool cmp2(int x,int y){
	if(tmp[x]!=tmp[y]) return tmp[x]<tmp[y];
	return tmp[x^at]<tmp[y^at];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>s;
	m=1<<n;
	FOR(i,0,m-1) p[i]=i;
	sort(p,p+m,cmp1);
	int cnt=rk[p[0]]=0;
	FOR(i,1,m-1) rk[p[i]]=cmp1(p[i-1],p[i])?++cnt:cnt;
	FOR(i,1,n){
		at=1<<(i-1);
		swap(rk,tmp);
		sort(p,p+m,cmp2);
		cnt=rk[p[0]]=0;
		FOR(j,1,m-1) rk[p[j]]=cmp2(p[j-1],p[j])?++cnt:cnt;
	}
	FOR(i,0,m-1) cout<<s[i^p[0]];
}