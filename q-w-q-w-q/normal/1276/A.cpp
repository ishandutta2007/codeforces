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
#define lb(x) ((x)&(-x))
#define sp(x,y) x^=y^=x^=y
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
int t,n;
char a[1000001];
bool ok[1000001];
int ans[1000001],s;
int main(){
	cin>>t;
	while(t--){
		scanf("%s",a+1);
		n=strlen(a+1);
		s=0;
		for(int i=1;i<=n-2;i++){
			if(a[i]=='o'&&a[i+1]=='n'&&a[i+2]=='e'){
				s++;
				if(a[i-1]=='o'){
					ans[s]=i+1;
					a[i+1]='-';
				}
				else ans[s]=i,a[i]='-';
			}
		}
		for(int i=1;i<=n-2;i++){
			if(a[i]=='t'&&a[i+1]=='w'&&a[i+2]=='o'){
				s++;
				if(a[i-1]=='t'){
					ans[s]=i+1;
					a[i+1]='-';
				}
				else ans[s]=i;
			}
		}
		wr(s),_e;
		for(int i=1;i<=s;i++)
		wr(ans[i]),_t;
		_e;
	}
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