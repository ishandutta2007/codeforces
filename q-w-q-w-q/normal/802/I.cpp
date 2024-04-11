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
char s[200005];
int t,n,sa[200005],rk[200005],tax[200005],tp[200005];
int height[200005],st[25][200005];
ll ans;
inline void radix_sort(int m){
	for(int i=1;i<=m;i++) tax[i]=0;
	for(int i=1;i<=n;i++) tax[rk[i]]++;
	for(int i=2;i<=m;i++) tax[i]+=tax[i-1];
	for(int i=n;i;i--) sa[tax[rk[tp[i]]]--]=tp[i];
}
inline void suffix_sort(){
	for(int i=1;i<27;i++) tax[i]=0;
	for(int i=1;i<=n;i++) tax[rk[i]=s[i]-'a'+1]++;
	for(int i=2;i<27;i++) tax[i]+=tax[i-1];
	for(int i=n;i;i--) sa[tax[s[i]-'a'+1]--]=i;
	for(int len=1,p=0,m=26;p<n;len<<=1,m=p){
		p=len;
		for(int j=1;j<=len;j++)
		tp[j]=n-len+j;
		for(int j=1;j<=n;j++)
		if(sa[j]>len) tp[++p]=sa[j]-len;
		radix_sort(m);
		std::swap(tp,rk);
		rk[sa[1]]=p=1;
		for(int i=2;i<=n;i++)
		rk[sa[i]]=(tp[sa[i]]==tp[sa[i-1]])&&(tp[sa[i]+len]==tp[sa[i-1]+len])?p:++p;
	}
}
inline void get_height(){
	int k=0,j;
	for(int i=1;i<=n;i++){
		if(k) k--;
		j=sa[rk[i]-1];
		while(s[i+k]==s[j+k]) k++;
		height[rk[i]]=k;
		st[0][rk[i]]=rk[i];
	}
}
inline void doubly(){
	for(int i=1;(1<<i)<=n;i++){
		for(int j=1;j+i-1<=n;j++){
			st[i][j]=height[st[i-1][j]]<=height[st[i-1][j+(1<<(i-1))]]?st[i-1][j]:st[i-1][j+(1<<(i-1))];
		}
	}
}
inline int query(int l,int r){
	int k=log2(r-l+1);
	return height[st[k][l]]<=height[st[k][r-(1<<k)+1]]?st[k][l]:st[k][r-(1<<k)+1];
}
inline void qwqwq(int l,int r,int lt){
	if(l>r) return;
	if(l==r){
		ans+=n-sa[l]+1-lt;
		return;
	}
	int k=query(l+1,r);
	ans+=1ll*(r-l+1)*(r-l+1)*(height[k]-lt);
	qwqwq(l,k-1,height[k]);
	int tp;
	while(k<r&&height[tp=query(k+1,r)]==height[k]){
		qwqwq(k,tp-1,height[k]);
		k=tp;
	}
	qwqwq(k,r,height[k]);
}
int main(){
	cin>>t;
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);
		suffix_sort();
		get_height();
		doubly();
		ans=0;
		qwqwq(1,n,0);
		wr(ans),_e;
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