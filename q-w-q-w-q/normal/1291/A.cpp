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
char ch,ss[1<<17],*A=ss,*B=ss;
inline char gc(){
	return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template <typename _Tp> inline void rd(_Tp &x);
template <typename _Tq> inline void wr(_Tq x);
template <typename _Tp> inline _Tp mx(_Tp x,_Tp y);
template <typename _Tp> inline _Tp mn(_Tp x,_Tp y);
int t,n,s,k;
char a[3001];
bool ok,tp;
int main(){
	cin>>t;
	while(t--){
		scanf("%d%s",&n,a+1);
		s=0;
		for(int i=1;i<=n;i++) s^=(a[i]-'0')&1;
		k=a[n]-'0';
		if(k%2==0){
			while(n>0&&(a[n]-'0')%2==0) n--;
			if(n==0){
				wr(-1),_e;
				continue;
			}
		}
		if(s==0){
			for(int i=1;i<=n;i++)
			putchar(a[i]);
			_e;
			continue;
		}
		ok=1,tp=1;
		for(int i=2;i<n&&ok;i++){
			if(a[i]!='0') tp=0;
			if((a[i]-'0')&1){
				for(int j=1;j<i;j++) putchar(a[j]);
				for(int j=i+1;j<=n;j++) putchar(a[j]);
				_e;
				ok=0;
			}
		}
		if(!ok) continue;
		if(tp||((a[1]-'0')%2==0)){
			wr(-1),_e;
			continue;
		}
		int i;
		for(i=2;a[i]=='0';i++);
		while(i<=n) putchar(a[i++]);
		_e;
	}
}
template <typename _Tp>
    inline void rd(_Tp &x){
    	o=0;
        x=0;
      	while (ch^45&&(ch<48||ch>57)) ch=gc();
      	if(ch==45)o=1,ch=gc();
        while(ch>47&&ch<58){
			x=(x<<1)+(x<<3)+(ch^48);
			ch=gc();
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