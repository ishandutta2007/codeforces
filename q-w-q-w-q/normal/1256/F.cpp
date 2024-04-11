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
int q,n;
char a[200001],b[200001];
int s1[26],s2[26];
int p[27],c[27];
int s[200001];
bool ok,ans;
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d%s%s",&n,a+1,b+1);
		ok=0,ans=1;
		for(int i=1;i<=n;i++){
			s[a[i]-'a']++;
			if(s[a[i]-'a']>1) ok=1;
		}
		for(int i=1;i<=n&&ans;i++){
			s[b[i]-'a']--;
			if(s[b[i]-'a']<0) ans=0;
		}
		if(!ans){
			for(int i=1;i<=n;i++)
			s[a[i]-'a']=s[b[i]-'a']=0;
			puts("NO");
			continue;
		}
		if(ok){
			for(int i=1;i<=n;i++)
			s[a[i]-'a']=s[b[i]-'a']=0;
			puts("YES");
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++)
		p[a[i]-'a']=i;
		for(int i=1;i<=n;i++){
			c[i]=p[b[i]-'a'];
			for(int j=i-1;j;j--)
			if(c[i]<c[j]) ans^=1;
		}
		puts(ans?"NO":"YES");
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