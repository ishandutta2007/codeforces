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


using namespace std;
typedef __int64 ll;

int n,m,k,a,bow,plate,dish[2],re;
int main(){
  scanf("%d %d %d",&n,&m,&k);
  int i,j;

  
  for(i=0;i<n;i++){
    scanf("%d",&a);
    dish[a-1]++;
    if(dish[0]>m || dish[0]+dish[1]>m+k){
      re++;
      if(dish[0])
        dish[0]--;
      else
        dish[1]--;
    }
  }
  cout<<re<<endl;
  return 0;
}