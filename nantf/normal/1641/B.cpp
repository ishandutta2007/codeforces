#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=666666,mod=998244353;
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
int n,a[maxn],al1,al2,a2[maxn],b[maxn],bl;
PII a1[maxn];
map<int,int> mp;
void clear(){
	mp.clear();
	al1=al2=bl=0;
}
void solve(){
	n=read();
	FOR(i,1,n) a[i]=read(),mp[a[i]]++;
	bool flag=true;
	FOR(i,1,n) if(mp[a[i]]%2) flag=false;
	if(!flag) puts("-1");
	else{
		while(n){
			int i=n-1;
			while(a[n]!=a[i]) i--;
			int at=i-1;
			bl=0;
			ROF(j,n-1,i+1) a1[++al1]=MP(at++,a[j]),b[++bl]=a[j];
			a2[++al2]=(n-i)*2;
			n=i-1;
			FOR(i,1,bl) a[++n]=b[i];
//			FOR(i,1,n) printf("%d ",a[i]);
//			puts("now");
		}
		printf("%d\n",al1);
		FOR(i,1,al1) printf("%d %d\n",a1[i].first,a1[i].second);
		printf("%d\n",al2);
		ROF(i,al2,1) printf("%d ",a2[i]);
		puts("");
	}
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}