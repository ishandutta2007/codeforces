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
int n;
int a[200001],b[200001];
int k[200001];
int main(){
	rd(n);
	for(int i=1;i<=n;i++)
	rd(a[i]);
	for(int i=1;i<=n;i++)
	rd(b[i]),k[b[i]]=i;
	int j=0;
	bool ok=1;
	if(k[1]){
		for(int i=k[1];i<n;i++)
		if(b[i]!=b[i+1]-1) ok=0;
		if(ok){
			int qwq=n-k[1]+1;
			for(int i=qwq+1;i<=n;i++){
				if(k[i]>0&&i-qwq-1<k[i]){
					wr(k[1]+n);
					return 0;
				}
			}
			wr(k[1]-1);
			return 0;
		}
	}
	if(k[1]) j=k[1];
	for(int i=1;i<=n;i++)
	if(b[i]>1) if(i-j>b[i]-1) j=i-b[i]+1;
	wr(j+n);
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