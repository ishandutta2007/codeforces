#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=111111,mod=998244353;
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
struct people{
	int p,c;
	bool operator<(const people &p)const{return c<p.c;}
}pp[maxn];
int n,m,res[maxn];
ll ans=1e18;
vector<ll> v[maxn];
ll calc(int i){
	ll s=0;
	int cnt=0;
	FOR(j,1,1e5) res[j]=0;
	FOR(j,1,1e5) if(v[j].size()>=i) cnt+=res[j]=max<int>(0,v[j].size()-(i-1)),s+=v[j][v[j].size()-(i-1)-1];
	FOR(j,1,n){
		if(v[0].size()+cnt>=i) break;
		if(pp[j].p && !res[pp[j].p]) s+=pp[j].c,cnt++;
		else res[pp[j].p]--;
	}
	if(v[0].size()+cnt>=i) return s;
	else return 1000000000000000000+i;
}
int main(){
	n=read();
	FOR(i,1,n){
		int p=read(),c=read();
		v[p].push_back(c);
		pp[i]=(people){p,c};
	}
	sort(pp+1,pp+n+1);
	FOR(i,0,1e5) sort(v[i].begin(),v[i].end());
	FOR(i,0,1e5) FOR(j,1,(int)v[i].size()-1) v[i][j]+=v[i][j-1];
	int l=max<int>(1,v[0].size()),r=n;
	while(l+2<r){
		int lmid=l+(r-l)/3,rmid=r-(r-l)/3;
		if(calc(lmid)<calc(rmid)) r=rmid;
		else l=lmid;
	}
	FOR(i,l,r) ans=min(ans,calc(i));
	printf("%lld\n",ans);
} // 19260817