#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=555;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,a[maxn][maxn],b[maxn][maxn];
int main(){
	n=read();m=read();
	FOR(i,1,n) FOR(j,1,m) a[i][j]=read();
	FOR(i,1,n) FOR(j,1,m) b[i][j]=read()^a[i][j];
	FOR(i,1,n){
		int cnt=0;
		FOR(j,1,m) if(b[i][j]) cnt++;
		if(cnt&1) return puts("No"),0;
	}
	FOR(j,1,m){
		int cnt=0;
		FOR(i,1,n) if(b[i][j]) cnt++;
		if(cnt&1) return puts("No"),0;
	}
	puts("Yes");
}