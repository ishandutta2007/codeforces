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
ll n,a[100001],tp,sum,k;
int main(){
	rd(n);
	for(int i=1;i<=n;i++)
	rd(a[i]);
	sort(a+1,a+1+n);
	if(n==1){
		if(a[1]&1) puts("sjfnb");
		else puts("cslnb");
		return 0;
	}
	if(a[1]==0&&a[2]==0){
		puts("cslnb");
		return 0;
	}
	tp=1;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]) tp++;
		else tp=1;
		if(tp>=3){
			puts("cslnb");
			return 0;
		}
		if(tp>=2) k++;
		if(tp==2&&a[i-2]+1==a[i]&&i>2){
			puts("cslnb");
			return 0;
		}
	}
	if(k>=2){
		puts("cslnb");
		return 0;
	}
	for(int i=1;i<=n;i++)
	sum+=a[i];
	sum-=(n-1)*n/2;
	if(sum&1) puts("sjfnb");
	else puts("cslnb");
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