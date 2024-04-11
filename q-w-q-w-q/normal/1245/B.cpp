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
int t,n,a,b,c,qwq;
char s[101];
char ans[101];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>a>>b>>c;
		scanf("%s",s+1);
		qwq=0;
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++){
			if(s[i]=='P'&&c) ans[i]='S',c--,qwq++;
			if(s[i]=='R'&&b) ans[i]='P',b--,qwq++;
			if(s[i]=='S'&&a) ans[i]='R',a--,qwq++;
		}
		if(qwq*2>=n){
			puts("YES");
			for(int i=1;i<=n;i++){
				if(ans[i]) putchar(ans[i]);
				else if(a) putchar('R'),a--;
				else if(b) putchar('P'),b--;
				else putchar('S'),c--;
			}
			_e;
		}
		else puts("NO");
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