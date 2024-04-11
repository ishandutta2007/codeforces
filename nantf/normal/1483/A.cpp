#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222,mod=998244353;
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
int n,m,cnt[maxn],ans[maxn];
vector<int> v[maxn];
void clear(){
	FOR(i,1,n) cnt[i]=0;
	FOR(i,1,m) v[i].clear();
}
void solve(){
	n=read();m=read();
	FOR(i,1,m){
		int k=read();
		while(k--) v[i].PB(read());
	}
	FOR(i,1,m) if((int)v[i].size()==1) cnt[v[i][0]]++,ans[i]=v[i][0];
	bool flag=true;
	FOR(i,1,n) if(cnt[i]>(m+1)/2){flag=false;puts("NO");break;}
	if(flag){
		puts("YES");
		FOR(i,1,m) if((int)v[i].size()!=1){
			int x=v[i][0],y=v[i][1];
			if(cnt[x]+1<=(m+1)/2) cnt[x]++,ans[i]=x;
			else cnt[y]++,ans[i]=y;
		}
		FOR(i,1,m) printf("%d ",ans[i]);
		puts("");
	}
	clear();
}
int main(){
	int T=read();
	while(T--) solve(); 
}