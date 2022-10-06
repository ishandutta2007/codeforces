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
#include "benri.h"
#else
#define out(args...)
#endif
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
const ll MOD=1e9+7; //998244353

void manacher(const string &st,vector<int> &re){
  re.resize(st.size());
  int i=0,j=0,n=st.size();
  while(i<st.size()){
    while(i-j>=0 && i+j<n && st[i-j]==st[i+j]) ++j;
    re[i]=j;
    int k = 1;
    while(i-k>=0 && i+k<st.size() && k+re[i-k]<j) re[i+k]=re[i-k], ++k;
    i+=k; j=max(0,j-k);
  }
}

string solve(const string &s){
	int n=s.size();
	{
		auto t=s;
		reverse(all(t));
		if(t==s) return s;
	}
	int len=0;
	for(int l=0,r=n-1;l<r&&s[l]==s[r];++l,--r) ++len;
	// out(len,1);
	vector<int> man;
	{
		string t(n*2+1,'.');
		rep(i,n) t[i*2+1]=s[i];
		// out(t,1);
		manacher(t,man);
	}
	// out(man,1);
	pii re(0,0);
	rep(c,man.size()){
		const int l=(c-1-man[c])/2+1,r=(c+man[c])/2-1;
		if(l>r) continue;
		//out(c,l,r,1);
		pii mn(MOD,0);
		if(l<=len){
			const int ln=len+len+c-len*2;
			MN(mn,pii(ln,ln-len));
			//out(c,l,ln,1);
		}
		if(n-1-len<=r){
			const int ln=len+len+(n-len)*2-c;
			MN(mn,pii(ln,len));
			//out(c,r,ln,1);
		}
		if(mn.X!=MOD) MX(re,mn);
	}
	int l=re.Y;
	int r=re.X-l;
	return s.substr(0,l)+s.substr(n-r);
}

string bf(string s,string res){
	int n=s.size();
	int ok=0;
	string re;
	rep(i,n+1)reps(j,i,n+1){
		string t=s.substr(0,i)+s.substr(j);
		if(t==res) ok=1;
		auto tt=t; reverse(all(tt));
		if(t==tt && re.size()<t.size()) re=t;
	}
	if(!ok) return "";
	return re;
}

int main(){
	rep(_,0*10000){
		int n=rand()%10+1;
		string s(n,'0');
		rep(i,n)if(rand()%2) s[i]++;
		auto act=solve(s);
		auto exp=bf(s,act);
		if(act.size()!=exp.size()){
			out(s,act,exp,1);
			exit(0);
		}
	}
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		cout<<solve(s) NL;
	}
  return 0;
}