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

int main(){
  int i,j,k;
  int n;
  cin>>n;
  vector<int> a(n);
  iota(all(a),1);
  for(i=2;i<=n;i++){
    int tmp=a[(i-1+n/i*i-1)%n];
    rrep(j,n/i-1){
      a[(i-1+(j+2)*i-1)%n]=a[(i-1+(j+1)*i-1)%n];
      //      cout<<"a["<<(i-1+(j+2)*i-1)%n<<"]=a["<<(i-1+(j+1)*i-1)%n<<"]\n";
    }
    if(n%i){
      a[(i-1+i-1)%n]=a[(i-1+n-1)%n];
      a[(i-1+n-1)%n]=tmp;
      //    cout<<"a["<<(i-1+i-1)%n<<"]=a["<<(i-1+n-1)%n<<"]\n";
      //   cout<<"a["<<(i-1+n-1)%n<<"]=a["<<(i-1+n/i*i-1)%n<<"]\n";
    }else{
      a[(i-1+i-1)%n]=tmp;
      //   cout<<"a["<<(i-1+i-1)%n<<"]=a["<<(i-1+n/i*i-1)%n<<"]\n";
    }
    //  rep(j,n)cout<<a[j]<<",";cout<<endl;
    //  rep(j,n)cout<<a[(i-1+j)%n]<<",";cout<<endl;
    // cout<<endl;
  }
  rep(i,n)
    cout<<a[(n-1+i)%n]<<" ";cout<<endl;
  return 0;
}