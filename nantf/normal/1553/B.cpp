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
int n,m;
char s[maxn],t[maxn];
void solve(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);m=strlen(t+1);
	FOR(i,1,n) FOR(j,1,n){
		if((i-j+m+1)%2) continue;
		int y=(i-j+m+1)/2;
		int x=m+1-y;
		if(x<1 || x>m || y<1 || y>m || i+x-1>n) continue;
		bool flag=true; 
		FOR(k,1,x) if(t[k]!=s[i+k-1]){flag=false;break;}
		FOR(k,1,y) if(t[m-k+1]!=s[j+k-1]){flag=false;break;}
		if(flag) return puts("YES"),void();
	}
	puts("NO");
}
int main(){
	int T;
	read(T);
	while(T--) solve();
}