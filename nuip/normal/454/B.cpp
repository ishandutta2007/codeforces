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


int main(){
  int i,j,k;
  int a[112345],n;
  vector<int> ans;
  cin>>n;
  rep(i,n)
    cin>>a[i];
  for(i=0;i<n-1;i++){
   if(a[i+1]<a[i])
     ans.pb(i);
  }
  if(ans.empty()){
    cout<<0<<endl;
    return 0;
  }
  if(a[n-1]>a[0] || ans.size()>1){
    cout<<-1<<endl;
    return 0;
  }
  cout<<n-1-ans[0]<<endl;
  return 0;
}