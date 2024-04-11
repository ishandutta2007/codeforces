#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1020;
int a,pre[N][N*2];Pii b[N][N*2];
Pii q[N*N*2];
int main() {
	read(a);memset(pre,-1,sizeof(pre));
	
	
	int f=0,r=1;q[f]=Pii(0,N);
	while(f!=r){
		Pii s=q[f++];int x=s.fi,y=s.se;
		rep(i,0,9){
			int nx=(x+i*a)/10,ny=y+i-(x+i*a)%10*a;
			if(ny>0&&ny<N*2&&!(x==0&&y==N&&i==0)&&pre[nx][ny]==-1){
				pre[nx][ny]=i;b[nx][ny]=s;q[r++]=Pii(nx,ny);
			}
		}
	}
	if(pre[0][N]==-1){puts("-1");return 0;}
	int x=0,y=N;bool ok=0;
	while(1){
		if(pre[x][y])ok=1;if(ok)printf("%d",pre[x][y]);
		Pii s=b[x][y];x=s.fi;y=s.se;
		if(x==0&&y==N)break;
	}
	return 0;
}