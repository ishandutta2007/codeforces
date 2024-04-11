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

int n,used[1123456];

int main(){
  int i,j,tmp,xx=0;
  scanf("%d",&n);
  cout<<n<<endl;
  for(i=0;i<n;i++){
    scanf("%d",&tmp);
    used[tmp]=1;
  }
  for(i=1;i<=1000000;i++){
    if(used[i]==0)continue;
    if(used[1000000+1-i]){
  //    cout<<i<<"!";
      xx++;
    }else{
      printf("%d ",1000000+1-i);
      //used[1000000+1-i]=1;
    }
  }
//  cout<<"\\"<<xx<<endl;
  for(i=1;i<=1000000;i++){
    if(xx<=0)break;
    if(used[i]+used[1000000+1-i]==0){
      printf("%d %d ",i,1000000+1-i);
      xx-=2;
    }
  }
  return 0;
}