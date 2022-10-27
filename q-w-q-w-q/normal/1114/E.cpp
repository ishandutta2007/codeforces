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
int l,r,ans,n,m,k,q,tp;
bool ok[1000001];
int a[1000001],s;
inline int gcd(int a,int b){
	while(a%b){
		k=b;
		b=a%b;
		a=k;
	}
	return b;
}
int main(){
	cin>>n;
	l=0,r=1e9;
	while(l<=r){
		m=l+r>>1;
		cout<<'>'<<' '<<m<<endl;
		cin>>k;
		cout.flush();
		if(k==0) ans=m,r=m-1;
		else l=m+1;
		tp++;
	}
	srand(19260817);
	while(tp<60&&a[s]^-1&&s<n){
		k=rand()*rand()%n+1;
		while(ok[k]) k=rand()*rand()%n+1;
		ok[k]=1;
		cout<<'?'<<' '<<k<<endl;
		cin>>a[++s];
		cout.flush();
		tp++;
	}
	if(a[s]==-1) s--;
	sort(a+1,a+1+s);
	s=unique(a+1,a+1+s)-a-1;
	for(int i=1;i<s;i++)
	q=gcd(q,a[i+1]-a[i]);
	cout<<'!'<<' '<<ans-q*(n-1)<<' '<<q<<endl;
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