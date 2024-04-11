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

priority_queue<ll> st;

int main(){
  int i,j,k,n;
  ll re=0,tmp;
  cin>>n;
  rep(i,n){
    cin>>tmp;
    st.push(tmp);
    re+=tmp;
  }
  ll a;
  while(1){
    a=st.top();st.pop();
    if(st.empty())
      break;
    a+=st.top();st.pop();
    re+=a;
    st.push(a);
  }
  cout<<re<<endl;
  return 0;
}