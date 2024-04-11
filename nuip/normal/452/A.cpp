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
  int i,j,k,n,f=0;
  string str,ans[]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
  cin>>n>>str;
  rep(i,8){
    f=0;
    rep(j,ans[i].size()){
      if(str[j]=='.')continue;
      if(ans[i][j]!=str[j]){
        f=1;
        break;
      }
    }
    if(!f){
      cout<<ans[i]<<endl;
      return 0;
    }
  }
  return 0;
}