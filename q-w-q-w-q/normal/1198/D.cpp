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
#include<ctime>
#define _t putchar(32)
#define _e putchar(10)
#define inf 2147483647
#define ine -2147483647
#define lb(x) (x)&(-x)
#define ic(x) ((x>='0'&&x<='9')||(x>='A'&&x<='Z')||(x>='a'&&x<='z'))
using namespace std;
typedef long long ll;
bool o;
char chh,ss[1<<17],*A=ss,*B=ss;
inline char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
inline void getstr(char *a,int &n){
    a[n=1]=gc();
    while(!ic(a[1])) a[1]=gc();
    while(ic(a[n])) a[++n]=gc();
    n--;
}
template <typename _Tp> inline void rd(_Tp &x);
template <typename _Tp> inline void wr(_Tp x);
template <typename _Tp> inline _Tp mx(_Tp x,_Tp y);
template <typename _Tp> inline _Tp mn(_Tp x,_Tp y);
int n,s[51][51],a[51][51];
int f[51][51][51][51];
char ch;
inline int sum(int x1,int y1,int x2,int y2){
	return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
}
inline int dfs(int x1,int y1,int x2,int y2){
	if(sum(x1,y1,x2,y2)==0) return 0;
	if(f[x1][y1][x2][y2]^-1) return f[x1][y1][x2][y2];
	f[x1][y1][x2][y2]=mx(x2-x1+1,y2-y1+1);
	for(int i=x1;i<x2;i++)
	f[x1][y1][x2][y2]=mn(f[x1][y1][x2][y2],dfs(x1,y1,i,y2)+dfs(i+1,y1,x2,y2));
	for(int j=y1;j<y2;j++)
	f[x1][y1][x2][y2]=mn(f[x1][y1][x2][y2],dfs(x1,y1,x2,j)+dfs(x1,j+1,x2,y2));
	return f[x1][y1][x2][y2];
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>ch;
			if(ch=='#'){
				a[i][j]=1;
				s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+1;
			}
			else s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}
	}
	memset(f,-1,sizeof(f));
	wr(dfs(1,1,n,n));
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