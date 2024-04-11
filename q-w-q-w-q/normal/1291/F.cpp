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
int n,k,ans,g;
char x;
bool ok[1025];
inline void c(int i){
	if(!ok[i]) return;
	printf("? %d\n",i);
	cout.flush();
	cin>>x;
	if(x=='Y') ok[i]=0;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) ok[i]=1;
	if(k==1){
		for(int i=1;i<=n;i++){
			if(!ok[i]) continue;
			ans++;
			for(int j=i+1;j<=n;j++){
				if(!ok[j]) continue;
				puts("R");
				c(i),c(j);
			}
		}
		printf("! %d\n",ans);
		return 0;
	}
	for(int i=0;i<n;i+=k){
		puts("R");
		cout.flush();
		for(int j=1;j<=k;j++) c(i+j);
	}
	for(int len=k;len<n;len<<=1){
		for(int i=0;i<n;i+=(len<<1)){
			/*puts("R");
			cout.flush();
			for(int b=i+len+1;b<i+(len<<1);b+=k){
				g=b-1;
				for(int j=0;j<len*2/k;j++){
					for(int t=1;t<=k/2;t++) c(i+j*k/2+t);
					for(int t=1;t<=k/2;t++) c(g+t);
					g+=k/2;
					if(g==i+(len<<1)) g=i+len;
				}
			}
			for(int j=1;j<=k/2;j++) c(i+j);*/
			for(int p=i;p<i+len;p+=k/2){
				for(int q=i+len;q<i+(len<<1);q+=k/2){
					puts("R");
					cout.flush();
					for(int j=1;j<=k/2;j++) c(p+j);
					for(int j=1;j<=k/2;j++) c(q+j);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	if(ok[i]) ans++;
	printf("! %d\n",ans);
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