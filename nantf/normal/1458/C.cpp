#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111,maxm=111111,mod=998244353;
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
int n,m,dx,dy,d,a[maxn][maxn],b[maxn][maxn],p[maxn],q[maxn],stk[maxn],tp;
char s[maxm];
void clear(){
	dx=dy=tp=d=0;
}
inline void push(int x){
	if(tp && stk[tp]==x) tp--;
	else stk[++tp]=x;
}
void getq(){
	FOR(i,1,n) q[p[i]]=i;
}
void workr(){
	FOR(i,1,n){
		FOR(j,1,n) p[j]=a[i][j];
		getq();
		FOR(j,1,n) a[i][j]=q[j];
	}
}
void workc(){
	FOR(i,1,n){
		FOR(j,1,n) p[j]=a[j][i];
		getq();
		FOR(j,1,n) a[j][i]=q[j];
	}
}
inline int hhh(int x){return x?x:n;}
void solve(){
	n=read();m=read();
	FOR(i,1,n) FOR(j,1,n) a[i][j]=read();
	scanf("%s",s+1);
	FOR(i,1,m){
		switch(s[i]){
			case 'R':
				dy=(dy-1+n)%n; 
				break;
			case 'L':
				dy=(dy+1+n)%n;
				break;
			case 'D':
				dx=(dx-1+n)%n;
				break;
			case 'U':
				dx=(dx+1+n)%n;
				break;
			case 'I':
				swap(d,dy);
				d=(n-d)%n;
				dy=(n-dy)%n;
				push(0);
				break;
			case 'C':
				swap(d,dx);
				d=(n-d)%n;
				dx=(n-dx)%n;
				push(1);
				break;
		}
//		FOR(i,1,tp) printf("%d",stk[i]);
//		printf(",dx=%d,dy=%d,d=%d\n",dx,dy,d);
	}
	while(tp>=24) tp-=24;
	FOR(i,1,tp){
		if(stk[i]) workc();
		else workr();
	}
	FOR(i,1,n){
		FOR(j,1,n) printf("%d ",hhh((a[hhh((i+dx)%n)][hhh((j+dy)%n)]+d)%n));
		puts("");
	}
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}
/*
1000

3 1
1 2 3
2 3 1
3 1 2
LDICRUCILDICRUCI

3 2
1 2 3
2 3 1
3 1 2
LDICRUCILDICRUCI

3 3
1 2 3
2 3 1
3 1 2
LDICRUCILDICRUCI

3 4
1 2 3
2 3 1
3 1 2
LDICRUCILDICRUCI

3 5
1 2 3
2 3 1
3 1 2
LDICRUCILDICRUCI

3 6
1 2 3
2 3 1
3 1 2
LDICRUCILDICRUCI

3 7
1 2 3
2 3 1
3 1 2
LDICRUCILDICRUCI

3 8
1 2 3
2 3 1
3 1 2
LDICRUCILDICRUCI

2 3 1
3 1 2
1 2 3
----------------1-------------------
1 2 3
2 3 1
3 1 2
----------------2-------------------
1 2 3
3 1 2
2 3 1
----------------3-------------------
1 2 3
3 1 2
2 3 1
----------------4-------------------
3 1 2
2 3 1
1 2 3
----------------5-------------------
2 3 1
1 2 3
3 1 2
----------------6-------------------
2 3 1
1 2 3
3 1 2
----------------7-------------------
3 1 2
1 2 3
2 3 1
----------------8-------------------
1 2 3
2 3 1
3 1 2
----------------9-------------------
3 1 2
1 2 3
2 3 1
----------------10-------------------
2 3 1
1 2 3
3 1 2
----------------11-------------------
2 3 1
1 2 3
3 1 2
----------------12-------------------
1 2 3
3 1 2
2 3 1
----------------13-------------------
3 1 2
2 3 1
1 2 3
----------------14-------------------
3 1 2
2 3 1
1 2 3
----------------15-------------------
2 3 1
3 1 2
1 2 3
----------------16-------------------
*/