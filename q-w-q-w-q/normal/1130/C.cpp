#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
#include<cstdlib>
#define _t putchar(32)
#define _e putchar(10)
#define inf 2147483647
#define ine -2147483647
#define lb(x) (x)&(-x)
using namespace std;
typedef long long ll;
bool o;
char chh,ss[1<<17],*A=ss,*B=ss;
inline char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template <typename _Tp> inline void rd(_Tp &x);
template <typename _Tp> inline void wr(_Tp x);
template <typename _Tp> inline _Tp mx(_Tp x,_Tp y);
template <typename _Tp> inline _Tp mn(_Tp x,_Tp y);
int n,a[51][51],bx,by,ex,ey,ans;
int ok[51][51];
int fx[5]={0,-1,0,0,1},fy[5]={0,0,-1,1,0};
inline void qwq(int x,int y,int k){
	if(x==0||y==0||x>n||y>n) return;
	ok[x][y]=k;
	for(int i=1;i<5;i++){
		if(!ok[x+fx[i]][y+fy[i]]&&a[x+fx[i]][y+fy[i]]!=1) qwq(x+fx[i],y+fy[i],k);
	}
}
int main(){
	cin>>n>>bx>>by>>ex>>ey;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	scanf("%1d",&a[i][j]);
	qwq(bx,by,1);
	if(ok[ex][ey]==1){
		wr(0);
		return 0;
	}
	qwq(ex,ey,2);
	ans=inf;
	for(int ix=1;ix<=n;ix++){
		for(int iy=1;iy<=n;iy++){
			if(ok[ix][iy]==0) continue;
			for(int jx=1;jx<=n;jx++){
				for(int jy=1;jy<=n;jy++){
					if(ok[jx][jy]&&ok[ix][iy]!=ok[jx][jy]) ans=mn(ans,(ix-jx)*(ix-jx)+(iy-jy)*(iy-jy));
				}
			}
		}
	}
	wr(ans);
}
template <typename _Tp>
    inline void rd(_Tp &x){
    	o=0;
        x=0;
      	while (chh^45&&(chh<48||chh>57)) chh=gc();
      	if(chh==45)o=1,chh=gc();
        while(chh>47&&chh<58){
            x=(x<<1)+(x<<3)+(chh^48);
            chh=gc();
        }
      	if(o) x=-x;
 	}
template <typename _Tp>
    inline void wr(_Tp x){
        if(x<0) x=-x,putchar(45);
        if(x<10){
            putchar(x+48);
            return;
        }
        wr(x/10);
        putchar(x%10+48);
    }
template <typename _Tp>
    inline _Tp mx(_Tp x,_Tp y){
        return x>y?x:y;
    }
template <typename _Tp>
    inline _Tp mn(_Tp x,_Tp y){
        return x<y?x:y;
    }