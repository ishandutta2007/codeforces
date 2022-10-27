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
char a[1000001],p[1000001];
int n,ans;
int l,r;
int main(){
	//freopen("experiment.in","r",stdin);
	//freopen("experiment.out","w",stdout);
	scanf("%s",a+1);
	n=strlen(a+1);
	l=1,r=n;
	while(l<=r){
		if(l==r){
			printf("%s",p+1);
			printf("%c",a[l]);
			for(int i=ans;i;i--)printf("%c",p[i]);
			return 0;
		}
		if(a[l]==a[r]) p[++ans]=a[l],l++,r--;
		else{
			if(l+2>=r){
				printf("%s",p+1);
				printf("%c",a[l]);
				for(int i=ans;i;i--)printf("%c",p[i]);
				return 0;
			}
			if(a[l+1]==a[r]){
				p[++ans]=a[r];
				l+=2,r--;
			}
			else if(a[r-1]==a[l]){
				p[++ans]=a[l];
				l++,r-=2;
			}
			else{
				p[++ans]=a[l+1];
				l+=2,r-=2;
			}
		}
	}
	printf("%s",p+1);
	for(int i=ans;i;i--)
	printf("%c",p[i]);
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