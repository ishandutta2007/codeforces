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
#define rep(X,Y) for (int (X) = 0;(X) < int(Y);++(X))
#define rrep(X,Y) for (int (X) = int(Y-1);(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
  int i,j,k;
  vector<int> n(6);
  rep(i,6)
    cin>>n[i];
  sort(all(n));
  do{
    if(n[0]==n[1] && n[0]==n[2] && n[0]==n[3]){
      if(n[4]==n[5]){
        cout<<"Elephant"<<endl;
      }else{
        cout<<"Bear"<<endl;
      }
      return 0;
    }
  }while(next_permutation(all(n)));
  cout<<"Alien"<<endl;
  return 0;
}