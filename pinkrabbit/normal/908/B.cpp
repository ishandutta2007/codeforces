#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
using namespace std;
const int INF=0x3f3f3f3f;
inline void qw(int&X){scanf("%d",&X);}
inline void qw(int&X,int&Y){scanf("%d%d",&X,&Y);}
inline void qw(int&X,int&Y,int&Z){scanf("%d%d%d",&X,&Y,&Z);}
inline int Max(int X,int Y){return X<Y?Y:X;}
inline int Min(int X,int Y){return X<Y?X:Y;}
inline int Abs(int X){return X<0?-X:X;}
inline ll Max(ll X,ll Y){return X<Y?Y:X;}
inline ll Min(ll X,ll Y){return X<Y?X:Y;}
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
int n,m,len,cnt,sx,sy,ex,ey;
int fk[60][60];
int per[4]={0,1,2,3};
char str[2449];
void check(){
	int nx=sx, ny=sy;
	F2(i,0,len){
		int dir=per[str[i]-'0'];
		nx=nx+dx[dir], ny=ny+dy[dir];
		if(!fk[nx][ny]) break;
		if(nx==ex&&ny==ey) {++cnt; return;}
	}
}
int main(){
	qw(n,m);
	F(i,1,n){
		F(j,1,m){
			char ch=getchar();
			if(ch=='.') fk[i][j]=1;
			else if(ch=='#') fk[i][j]=0;
			else if(ch=='S') sx=i, sy=j, fk[i][j]=1;
			else if(ch=='E') ex=i, ey=j, fk[i][j]=1;
			else --j;
		}
	}
	scanf("%s",str); len=strlen(str);
	F(k,1,23){
		check();
		next_permutation(per,per+4);
	}check();
	printf("%d",cnt);
	return 0;
}