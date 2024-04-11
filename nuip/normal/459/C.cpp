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
//--
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<cstring>
#include<sstream>
#include<complex>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = Y-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int pow2(int a,int b,int n){int s=1;
rep(i,b){
s*=a;
if(s>=n)return 1;
}return 0;}
int main(){
  ll i,j;
  ll n,d,k;
  cin>>n>>k>>d;
  if(n<=k){
    rep(i,d){
      rep(j,n)
        cout<<1+j<<" ";
      cout<<endl;
    }
  }else if(!pow2(k,d,n)){
    cout<<-1<<endl;
  }else{
    ll hoge=1;
    rep(i,d){
      if(hoge<n && hoge>0){
        rep(j,n)
          cout<<1+(j/hoge)%k<<" ";
        hoge*=k;
      }
      else
        rep(j,n)
          cout<<"1 ";
      cout<<endl;
    }
  }
  return 0;
}