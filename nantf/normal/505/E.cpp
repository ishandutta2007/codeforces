#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010;
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
int n,m,k,p,h[maxn],a[maxn],cnt[maxn],at;
vector<int> v[maxn];
bool yet_another_check(ll x,int rem){
	ll sum=0;
	FOR(i,1,n) sum+=max(0ll,(h[i]+1ll*m*a[i]-x+p-1)/p-cnt[i]);
	return sum<=rem;
}
bool check(ll x){
	FOR(i,1,m) v[i].clear();
	FOR(i,1,n){
		cnt[i]=0;
		ll d=x/a[i]+1;
		if(d<=m) v[d].PB(i);
	}
	at=0;
	FOR(i,1,m){
		while(at<=m && v[at].empty()) at++;
		if(at>m) return yet_another_check(x,k*(m-i+1));
		if(at<=i) return false;
		FOR(j,1,k){
			int id=v[at].back();
			v[at].pop_back();
			while(at<=m && v[at].empty()) at++;
			if(at>m) return yet_another_check(x,k-j+1+k*(m-i));
			cnt[id]++;
			ll d=(x+1ll*cnt[id]*p)/a[id]+1;
			if(d<=m) v[d].PB(id);
		}
	}
	return yet_another_check(x,0);
}
int main(){
	n=read();m=read();k=read();p=read();
	FOR(i,1,n) h[i]=read(),a[i]=read();
	ll l=0,r=2e14;
	while(l<r){
		ll mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1; 
	}
	printf("%lld\n",l);
}
// shit remotejudge