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
#include<cstdio>
#include<cstring>
#include<sstream>
#define X first
#define Y second
#define pb push_back
#define pqPair priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >
#define all(X) (X).begin(),(X).end()

using namespace std;
typedef __int64 ll;

int num[5123];
vector<int> res;

int main(){
  int a,n,i,j;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a);
    num[a]++;
  }
  for(i=1;i<5005;i++){
    if(num[i]){
      res.pb(i);
      num[i]--;
    }
  }
  for(i=5000;i>0;i--){
    if(num[i] && res.back()!=i){
      res.pb(i);
      num[i]--;
    }
  }
  cout<<res.size()<<endl;
  for(i=0;i<res.size();i++){
    printf("%d%c",res[i],(i==res.size()-1?'\n':' '));
  }
  return 0;
}