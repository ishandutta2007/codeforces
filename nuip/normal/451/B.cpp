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
  int i,j,k,n,l,r;
  cin>>n;
  vector<int> a(n),b;
  rep(i,n)
    cin>>a[i];
  b=a;
  sort(all(b));
  l=-1;
  rep(i,n)
    if(a[i]!=b[i]){
      l=i;
      break;
    }
  if(l<0){
    cout<<"yes\n1 1\n";
    return 0;
  }
  r=-1;
  rep(i,n){
    if(a[n-1-i]!=b[n-1-i]){
      r=n-1-i;
      break;
    }
  }
  reverse(a.begin()+l,a.begin()+r+1);
//  rep(i,n)cout<<a[i]<<" ";cout<<endl;
  if(a==b){
    cout<<"yes"<<endl;
    cout<<l+1<<" "<<r+1<<endl;
  }else{
    cout<<"no"<<endl;
  }
  return 0;
}