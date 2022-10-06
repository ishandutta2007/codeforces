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
#define repe(X,Y) for ((X) = 0;(X) < int(Y);++(X))
#define peat(X,Y) for (;(X) < int(Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

string strs[]={"qwertyuiop",
"asdfghjkl;",
"zxcvbnm,./"};

int main(){
  std::ios_base::sync_with_stdio(false);
  int i,j,k,d;
  string str;
  cin>>str;
  d=(str[0]=='R'?-1:1);
  cin>>str;
  rep(i,str.size()){
    rep(j,3){
      rep(k,strs[j].size()){
        if(str[i]==strs[j][k])
          cout<<strs[j][k+d];
      }
    }
  }
  return 0;
}