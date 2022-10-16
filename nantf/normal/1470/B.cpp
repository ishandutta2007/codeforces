#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111111,mod=998244353;
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
int n,a[maxn],q,id[maxn],cnt[maxn],tmp[maxn],tl;
void clear(){
	FOR(i,1,n) cnt[a[i]]=0;
	tl=0;
}
void solve(){
	n=read();
	FOR(i,1,n) a[i]=id[read()];
	int mx=0,omx=0,esum=0;
	FOR(i,1,n) cnt[a[i]]++,tmp[++tl]=a[i];
	sort(tmp+1,tmp+tl+1);tl=unique(tmp+1,tmp+tl+1)-tmp-1;
	FOR(ii,1,tl){
		int i=tmp[ii];
		mx=max(mx,cnt[i]);
		if(cnt[i]%2) omx=max(omx,cnt[i]);
		else esum+=cnt[i];
	}
	if(cnt[1]%2) esum+=cnt[1];
	q=read();
	while(q--){
		ll x=read();
		if(x){
			printf("%d\n",max(esum,omx));
		}
		else{
			printf("%d\n",mx);
		}
	}
	clear();
}
void init(){
	FOR(i,1,1e6) id[i]=i;
	FOR(i,2,1e6){
		FOR(jj,1,1e6/i){
			int j=i*jj;
			while(id[j]%(1ll*i*i)==0) id[j]/=i*i;
		}
	}
}
int main(){
	init();
	int T=read();
	while(T--) solve();
}
/*
2
4
6 8 4 2
2
0
1
5
12 3 20 80 1
2
1
0
*/