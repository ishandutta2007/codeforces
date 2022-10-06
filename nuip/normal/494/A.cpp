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
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < int(Y);++(X))
#define rrep(X,Y) for (int (X) = int(Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < int(Y);++(X))
#define peat(X,Y) for (;(X) < int(Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  string str;
  cin>>str;
  int n=0;
  rep(i,str.size())
    n+=(str[i]=='#');
  int re=-1;
  int p=0,pp=0;
  int l,r;
  j=0;
  rep(i,str.size()){
    if(str[i]=='('){
      p++;
      pp++;
    }else if(str[i]==')'){
      p--;
      pp--;
    }else{
      j++;
      if(j==n){
        re=max(1,p);
        pp=p-1;
        l=pp;
        r=0;
        p-=re;
      }else{
        p--;
      }
    }
    r=min(r,pp-l);
    if(re<0){
      if(p<0){
        cout<<-1<<endl;
        return 0;
      }
    }else{
      if(pp<0){
        cout<<-1<<endl;
        return 0;
      }
    }
  }
//  cout<<re<<","<<p<<","<<r<<","<<l<<endl;
  if(p>0){
    cout<<-1<<endl;
  }else{
    if(re+p<=0){
      cout<<-1<<endl;
      return 0;
    }else{
      if(l+1-(re+p)+r<0){
        cout<<-1<<endl;
        return 0;
      }
      rep(i,n-1)
        cout<<1<<endl;
      cout<<re+p<<endl;
    }
  }
return 0;
}