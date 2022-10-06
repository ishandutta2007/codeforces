#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#include<cassert>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define rreps(X,S,Y) for (int (X) = (Y)-1;(X) >= (S);--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define Endl endl
#define NL <<"\n"

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
template<class T> using vv=vector<vector<T>>;
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
//#undef NUIP
#ifdef NUIP
#include "../benri.h"
#else
#define out
#endif
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
const ll MOD=1e9+7; //998244353

void win(){
	cout<<"tokitsukaze"<<endl;
	exit(0);
}
void lose(){
	cout<<"quailty"<<endl;
	exit(0);
}
void draw(){
	cout<<"once again"<<endl;
	exit(0);
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n,t;
	cin>>n>>t;
	string s;
	cin>>s;
	vector<int> a(n);
	rep(i,n) a[i]=s[i]-'0';
	array<set<int>,2> st;
	rep(i,n) st[a[i]].insert(i);
	auto check=
		[&](){
			rep(i,2){
				if(st[i].empty()) return 1;
				if(*st[i].rbegin()-*st[i].begin()+1<=t) return 1;
			}
			return 0;
		};
	if(check()) win();
	out(a,1);
	auto bkup=st;
	rep(c,2){
		st=bkup;
		rep(i,t-1)if(a[i]!=c){
			st[1-c].erase(i);
			st[c].emplace(i);
		}
		reps(i,t-1,n){
			if(a[i]!=c){
				st[1-c].erase(i);
				st[c].emplace(i);
			}
			out(i,c,st,check(),1);
			if(!check()) draw();
			int l=i-t+1;
			if(a[l]!=c){
				st[c].erase(l);
				st[1-c].emplace(l);
			}
		}
	}
	lose();
  return 0;
}