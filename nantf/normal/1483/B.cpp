#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353;
#define PB push_back
#define MP make_pair
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
int n,a[maxn],ans[maxn],al,nxt[maxn],prv[maxn];
set<int> s;
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
void clear(){
	al=0;
	s.clear();
}
void solve(){
	n=read();
	FOR(i,0,n-1) a[i]=read();
	FOR(i,0,n-1) if(gcd(a[i],a[(i+1)%n])==1) s.insert(i);
	FOR(i,0,n-1) nxt[i]=(i+1)%n;
	FOR(i,0,n-1) prv[i]=(i-1+n)%n;
	int lst=-1;
	while(!s.empty()){
		set<int>::iterator it=s.lower_bound(lst);
		if(it==s.end()) it=s.begin();
		int now=nxt[*it];
		ans[++al]=now;
		if(gcd(a[prv[now]],a[now])==1) s.erase(prv[now]);
		if(gcd(a[now],a[nxt[now]])==1) s.erase(now);
		nxt[prv[now]]=nxt[now];
		prv[nxt[now]]=prv[now];
		if(gcd(a[prv[now]],a[nxt[now]])==1 && prv[now]!=now) s.insert(prv[now]);
		lst=now;
//		for(set<int>::iterator it=s.begin();it!=s.end();it++) printf("%d ",*it);
//		puts("");
	}
	printf("%d ",al);
	FOR(i,1,al) printf("%d ",ans[i]+1);
	puts("");
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}