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
#define lb(x) ((x)&(-(x)))
#define sp(x,y) x^=y^=x^=y
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
bool o;
char ch,SSS[1<<17],*A=SSS,*B=SSS;
inline char gc(){
	return A==B&&(B=(A=SSS)+fread(SSS,1,1<<17,stdin),A==B)?EOF:*A++;
}
template <typename _Tp> inline void rd(_Tp &x);
template <typename _Tq> inline void wr(_Tq x);
template <typename _Tp> inline _Tp mx(_Tp x,_Tp y);
template <typename _Tp> inline _Tp mn(_Tp x,_Tp y);
#define add(x,y) x+y<k?x+y:x+y-k
#define sub(x,y) x<y?x+k-y:x-y
int n,k,a[300001];
int st[20][300001];
int cnt,lc[600001],rc[600001],v[600001],s[600001],gu[600001];
int b[600001],e[600001];
ll ans,sum[1000001];
inline int query(int l,int r){
	int k=log2(r-l+1);
	return a[st[k][l]]>a[st[k][r-(1<<k)+1]]?st[k][l]:st[k][r-(1<<k)+1];
}
inline void build(int i,int l,int r){
	s[i]=r-l+1;
	b[i]=l,e[i]=r;
	if(l==r) v[i]=l;
	if(l>=r) return;
	v[i]=query(l,r);
	gu[i]=a[v[i]]%k;
	build(lc[i]=++cnt,l,v[i]-1),build(rc[i]=++cnt,v[i]+1,r);
}
inline void dfs(int i){
	if(b[i]>e[i]){
		sum[a[b[i]-1]]++;
		return;
	}
	if(b[i]==e[i]){
		sum[a[b[i]]]++,sum[a[b[i]-1]]++;
		return;
	}
	if(s[lc[i]]<s[rc[i]]){
		dfs(lc[i]);
		for(int j=b[i]-1;j<v[i];j++) sum[a[j]]=0;
		dfs(rc[i]);
		for(int j=b[i]-1;j<v[i];j++) ans+=sum[add(a[j],gu[i])];
		for(int j=b[i]-1;j<v[i];j++) sum[a[j]]++;
	}
	else{
		dfs(rc[i]);
		for(int j=v[i];j<=e[i];j++) sum[a[j]]=0;
		dfs(lc[i]);
		for(int j=v[i];j<=e[i];j++) ans+=sum[sub(a[j],gu[i])];
		for(int j=v[i];j<=e[i];j++) sum[a[j]]++;
	}
	ans--;
}
int main(){
	rd(n),rd(k);
	for(int i=1;i<=n;i++) rd(a[i]),st[0][i]=i;
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[j][i]=a[st[j-1][i]]>a[st[j-1][i+(1<<(j-1))]]?st[j-1][i]:st[j-1][i+(1<<(j-1))];
		}
	}
	build(cnt=1,1,n);
	for(int i=1;i<=n;i++) a[i]=(a[i]+a[i-1])%k;
	dfs(1);
	wr(ans);
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