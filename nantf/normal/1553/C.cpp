#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
template<typename T>
inline void read(T &x){
	x=0;
	bool f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	if(f) x=-x;
}
char s[maxn];
int c1,c2,ans;
void dfs(int dep){
	if(dep==11 || c1+(11-dep)/2<c2 || c2+(12-dep)/2<c1) return ans=min(ans,dep-1),void();
	if(s[dep]!='0'){
		(dep&1?c1:c2)++;
		dfs(dep+1);
		(dep&1?c1:c2)--;
	}
	if(s[dep]!='1') dfs(dep+1);
}
void solve(){
	scanf("%s",s+1);
	ans=10;
	dfs(1);
	printf("%d\n",ans);
}
int main(){
	int T;
	read(T);
	while(T--) solve();
}