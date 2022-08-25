/*
Author: QAQAutoMaton
Lang: C++
Code: F.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define debug(qaq...) fprintf(stderr,qaq)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
#define unq(a) sort(all(a)),a.erase(unique(all(a)),a.end())
using namespace std;
typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cp;
typedef pair<int,int> pii;
const double eps=1e-8;
const double pi=acos(-1.0);
template<class T,class T2>int chkmin(T &a,T2 b){return a>b?a=b,1:0;}
template<class T,class T2>int chkmax(T &a,T2 b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T,class T2>T mmin(T a,T2 b){return a<b?a:b;}
template<class T,class T2>T mmax(T a,T2 b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>int dcmp(T a,T b){return a>b;}
template<int *a>int cmp_a(int x,int y){return a[x]<a[y];}
template<class T>bool sort2(T &a,T &b){return a>b?swap(a,b),1:0;}
template<class T,class ...T2>T mmin(T a,T2 ...b){return mmin(a,mmin(b...));}
template<class T,class ...T2>T mmax(T a,T2 ...b){return mmax(a,mmax(b...));}
#define min mmin
#define max mmax
#define abs aabs

void read(int &x){scanf("%d",&x);}
void read(ull &x){scanf("%llu",&x);}
ull a[1000005];
#define cnt(x) __builtin_popcountll(a[x])
struct Stk{
	int s[1000005],t,c[1000005][61]; 
	void append(int x){
		s[++t]=x;
		for(int i=0;i<=60;++i)c[t][i]=c[t-1][i];
		c[t][cnt(x)]+=s[t]-s[t-1];
	}
	int query(int r,int v){
		int x=upper_bound(s+1,s+t+1,r)-s;
		int ans=c[x-1][v];
		if(x<=t && cnt(s[x])==v){
			ans+=min(s[x],r)-s[x-1];
		}
		return ans;
	}
	int query(int l,int r,int v){
		return query(r,v)-query(l-1,v);
	}
};
Stk ss;
int ad[1000005];
int s[1000005],t;
signed main(){
#ifdef QAQAutoMaton 
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	int n;
	read(n);
	for(int i=1;i<=n;++i){
		read(a[i]);
	}
	long long ans=0;
	//int su=0;
	for(int i=1;i<=n;++i){
		while(t && a[s[t]]<=a[i]){
			ad[i]-=ss.query(s[t-1]+1,s[t],cnt(s[t]));
			--t;
		}			
		s[++t]=i;
		ad[i]+=ss.query(s[t-1]+1,s[t]-1,cnt(s[t]));

		while(ss.t && a[ss.s[ss.t]]>=a[i]){
			--ss.t;
		}			
		ss.append(i);

		//ans+=s;
	}
	ss.t=0;
	t=0;
	for(int i=1;i<=n;++i){

		while(ss.t && a[ss.s[ss.t]]<=a[i]){
			--ss.t;
		}			
		ss.append(i);

		while(t && a[s[t]]>=a[i]){
			ad[i]-=ss.query(s[t-1]+1,s[t],cnt(s[t]));
			--t;
		}			
		s[++t]=i;
		ad[i]+=ss.query(s[t-1]+1,s[t],cnt(s[t]));


		//ans+=s;
	}
	int su=0;
	for(int i=1;i<=n;++i){su+=ad[i];ans+=su;}
	printf("%lld\n",ans);
	return 0;
}