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
int n,m,k,ans,x,y,s,l,sum;
int f[100001];
bool ok;
vector<int>q[100001];
int qu[100001],h,t;
inline int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
int main(){
	rd(n);
	rd(m);
	k=sqrt(m)+1;
	for(int i=1;i<=m;i++){
		rd(x);
		rd(y);
		q[x].push_back(y);
		q[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	sort(q[i].begin(),q[i].end());
	s=1,f[1]=1;
	h=0,t=1,qu[t]=1;
	ok=1;
	sum=1;
	while(h!=t&&s<k&&ok){
		x=qu[++h];
		l=0;
		for(int j=1;j<=n&&ok;j++){
			if(l<q[x].size()&&q[x][l]==j){
				l++;
				continue;
			}
			if(!f[j]){
				s++;
				f[j]=1;
				qu[++t]=j;
				sum++;
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(f[i]) continue;
		s=1,f[i]=i;
		h=0,t=1,qu[t]=i;
		ok=1;
		while(h!=t&&s<k&&ok){
			x=qu[++h];
			l=0;
			for(int j=1;j<=n&&ok;j++){
				if(l<q[x].size()&&q[x][l]==j){
					l++;
					continue;
				}
				if(!f[j]){
					s++;
					f[j]=i;
					qu[++t]=j;
				}
				else if(find(j)^i) ok=0;
			}
		}
		f[i]=1;
		if(ok&&(s<k||sum<k)) ans++;
		sum+=s;
	}
	wr(ans);
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