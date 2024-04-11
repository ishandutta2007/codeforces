#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=333;
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
int n,m,a[maxn][maxn];
void solve(){
	n=read();m=read();
	FOR(i,1,n) FOR(j,1,m) a[i][j]=read();
	FOR(i,1,n) FOR(j,1,m){
		if(i==1 && j==1) if(a[i][j]>2) return puts("NO"),void();
		if(i==1 && j==m) if(a[i][j]>2) return puts("NO"),void();
		if(i==n && j==1) if(a[i][j]>2) return puts("NO"),void();
		if(i==n && j==m) if(a[i][j]>2) return puts("NO"),void();
		if(i==1) if(a[i][j]>3) return puts("NO"),void();
		if(i==n) if(a[i][j]>3) return puts("NO"),void();
		if(j==1) if(a[i][j]>3) return puts("NO"),void();
		if(j==m) if(a[i][j]>3) return puts("NO"),void();
		if(a[i][j]>4) return puts("NO"),void();
	}
	puts("YES");
	FOR(i,1,n){
		FOR(j,1,m){
			if(i==1 && j==1) printf("2 ");
			else if(i==1 && j==m) printf("2 ");
			else if(i==n && j==1) printf("2 ");
			else if(i==n && j==m) printf("2 ");
			else if(i==1) printf("3 ");
			else if(i==n) printf("3 ");
			else if(j==1) printf("3 ");
			else if(j==m) printf("3 ");
			else printf("4 ");
		}
		puts("");
	}
}
int main(){
	int T=read();
	while(T--) solve(); 
}