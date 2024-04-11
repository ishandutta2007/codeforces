#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222,mod=998244353;
#define NO return puts("NO"),clear()
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0;bool f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
inline int qmo(int x){return x+((x>>31)&mod);}
int n,a[maxn],at[maxn],pl,ans[maxn];
PII pr[maxn];
vector<int> v[maxn];
void clear(){
	FOR(i,1,n) a[i]=at[i]=ans[i]=0,pr[i]=MP(0,0),v[i].clear();
	pl=0;
}
inline void sw(int x,int y){
//	printf("sw(%d,%d)\n",x,y);
	pr[++pl]=MP(x,y);
	if(a[x]==a[y]) return;
	at[at[x]]=y;
	at[at[y]]=x;
	swap(a[x],a[y]);
	swap(at[x],at[y]);
}
void solve(){
	n=read();
	FOR(i,1,n){
		a[i]=read();
		v[a[i]].PB(i);
	}
	int mex=1,p=0,mid=0;
	while(!v[mex].empty()) mex++;
	if(n%2){
		mid=(n+1)/2;
		int x=a[mid];
		if((int)v[x].size()==1) NO;
		v[x].erase(lower_bound(v[x].begin(),v[x].end(),mid));
		v[mex].PB(mid);
		v[mex].PB(v[x].back());
		v[x].pop_back();
	}
	FOR(i,1,n){
		while((int)v[i].size()>2){
			while(!v[mex].empty()) mex++;
			FOR(_,0,1) v[mex].PB(v[i].back()),v[i].pop_back();
		}
	}
	FOR(i,1,n) if((int)v[i].size()==1){
		if(p) NO;
		p=i;
		a[v[i][0]]=i;
	}
	else if((int)v[i].size()==2){
		at[v[i][0]]=v[i][1],at[v[i][1]]=v[i][0];
		a[v[i][0]]=a[v[i][1]]=i;
	}
	puts("YES");
	FOR(i,1,(n-1)/2){
		int j=n-i+1,x=i+1,y=at[x];
		bool flag=false;
		if(a[x]==p) x=j-1,y=at[x];
//		printf("i=%d,j=%d,x=%d,y=%d\n",i,j,x,y);
		if(a[j]==p) swap(i,j),flag=true;
		if(j==y) sw(i,y),sw(j,x);
		else sw(j,y),sw(i,x);
		if(flag) swap(i,j);
	}
	if(n%2==0) sw(n/2,n/2+1);
	FOR(i,1,n) ans[i]=i;
	FOR(i,1,pl) swap(ans[pr[i].fi],ans[pr[i].se]);
	FOR(i,1,n) printf("%d ",ans[i]);
	puts("");
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}