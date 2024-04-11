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
int n,k,a[maxn],b[maxn],at[maxn];
set<int> s;
bool in[maxn];
void clear(){
	s.clear();
	FOR(i,1,n) at[i]=in[i]=0;
}
void solve(){
	n=read();k=read();
	FOR(i,1,n) a[i]=read(),at[a[i]]=i;
	FOR(i,1,k) b[i]=read(),in[b[i]]=true;
	FOR(i,1,n) s.insert(i);
	int ans=1;
	FOR(i,1,k){
		set<int>::iterator it=s.lower_bound(at[b[i]]);
		int cnt=0;
		if(it!=s.begin()){
			set<int>::iterator it1=it;
			it1--;
			if(!in[a[*it1]]) cnt++;
		}
		set<int>::iterator it2=it;
		it2++;
		if(it2!=s.end() && !in[a[*it2]]) cnt++;
		ans=1ll*ans*cnt%mod;
		s.erase(it);
	}
	printf("%d\n",ans);
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}