#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222,mod=998244353;
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
inline int qmo(int x){return x+(x>>31?mod:0);}
int n,l,r,a[maxn];
vector<int> v1[maxn],v2[maxn];
void clear(){
	FOR(i,1,n) v1[i].clear(),v2[i].clear();
}
void solve(){
	n=read();l=read();r=read();
	FOR(i,1,n) a[i]=read();
	if(l>r) swap(l,r),reverse(a+1,a+n+1);
	FOR(i,1,l) v1[a[i]].PB(i);
	int res=(r-l)/2,ans=n/2+(r-l)/2;
	FOR(i,l+1,n){
		if(v1[a[i]].empty()) v2[a[i]].PB(i);
		else v1[a[i]].pop_back(),ans--;
	}
	FOR(i,1,n){
		while(res && (int)v2[i].size()>=2) v2[i].pop_back(),v2[i].pop_back(),ans--,res--;
	}
	printf("%d\n",ans);
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}
/*
1
6 1 5
1 2 3 4 5 6
*/