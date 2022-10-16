#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1000100,mod=998244353;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int t,n,d[333],pr[maxn],pl,id[maxn],mx[maxn],cnt,dl;
ll ans,dd[maxn];
bool vis[maxn];
void init(){
	FOR(i,2,1000000){
		if(!vis[i]) pr[++pl]=i;
		FOR(j,1,pl){
			if(i*pr[j]>1000000) break;
			vis[i*pr[j]]=true;
			if(i%pr[j]==0) break;
		}
	}
	FOR(i,1,pl){
		ll p=pr[i];
		while(p<=1000000){
			id[p]=i;
			p*=pr[i];
		}
	}
}
bool check(ll x){
	if(x>1e12) return false;
	sort(d+1,d+n+1);
	dl=0;
	for(ll i=2;i*i<=x;i++) if(x%i==0){
		dd[++dl]=i;
		if(i*i!=x) dd[++dl]=x/i;
	}
	if(n!=dl) return false;
	sort(dd+1,dd+dl+1);
	FOR(i,1,n) if(d[i]!=dd[i]) return false;
	return true;
}
int main(){
	init();
	t=read();
	while(t--){
		ans=1;cnt=0;
		MEM(mx,0);
		n=read();
		FOR(i,1,n){
			d[i]=read();
			if(id[d[i]]){
				if(!mx[id[d[i]]]) cnt++;
				mx[id[d[i]]]=max(mx[id[d[i]]],d[i]);
			}
		}
		FOR(i,1,pl) if(mx[i]){
			ans*=mx[i];
			if(cnt==1) ans*=pr[i];
			if(ans>1e12) break;
		}
		if(check(ans)) cout<<ans<<endl;
		else cout<<-1<<endl;
	}
}