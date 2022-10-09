//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <random>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
#define vi vector<int>
#define ull unsigned long long
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
using namespace std;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
namespace fastIO {
	template<class T>
	inline void read(T &x) {
		x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		if(fu)x=-x;
	}
	inline int read() {
		int x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		return fu?-x:x;
	}
	template<class T,class... Args>
	inline void read(T& t,Args&... args) {
		read(t);
		read(args...);
	}
	char _n_u_m_[40];
	template<class T>
	inline void write(T x) {
		if(x==0){
			putchar('0');
			return;
		}
		T tmp = x > 0 ? x : -x ;
		if( x < 0 ) putchar('-') ;
		int cnt = 0 ;
		while( tmp > 0 ) {
			_n_u_m_[ cnt ++ ] = tmp % 10 + '0' ;
			tmp /= 10 ;
		}
		while( cnt > 0 ) putchar(_n_u_m_[ -- cnt ]) ;
	}
	template<class T>
	inline void write(T x ,char ch) {
		write(x);
		putchar(ch);
	}
}
using namespace fastIO;
int n,id[400002],v[2000002],cnt,a[400002];
map<int,pair<int,set<int> > >S;
inline void orz(auto &a,auto &b){
	if(a.second.size()<b.second.size())swap(a,b),swap(v[a.first],v[b.first]);
	for(auto i:b.second)a.second.insert(i),id[i]=a.first;
}
int main() {
//	freopen("data.txt","r",stdin);
//	freopen("qwq.txt","w",stdout);
	cin>>n;
	F(i,1,n){
		int res=read();
		if(!S[res].first)v[S[res].first=++cnt]=res;
		id[i]=S[res].first;
		S[res].second.insert(i);
	}
	cnt=n;
	S[INT_MAX]=pair<int,set<int> >();
	F(iasdf,1,read()){
		int op=read();
		if(op==1){
			int i=read();
			S[v[id[i]]].second.erase(i);
			int res=read();
			if(!S[res].first)v[S[res].first=++cnt]=res;
			id[i]=S[res].first;
			S[res].second.insert(i);
		}else if(op==2)write(v[id[read()]],'\n');
		else{
			int l=read(),r=read();
			int mid=(l+r)>>1;
			if(!S.count(l-1))S[l-1].first=++cnt,v[cnt]=l-1;
			if(!S.count(r+1))S[r+1].first=++cnt,v[cnt]=r+1;
			auto i=S.lower_bound(l),j=S.lower_bound(mid+1),k=S.lower_bound(r+1);
			auto &t1=S[l-1],&t2=S[r+1];
			for(auto x=i;x!=j;++x)orz(t1,x->second);
			for(auto x=j;x!=k;++x)orz(t2,x->second);
			S.erase(i,k);
		}
	}
	return 0;
}
/*
10 5 3 3 5 5 4 6 5 2 5 
5
1 2 2
2 10 
3 4 7
3 2 3
2 8 
*/