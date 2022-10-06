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


int main(){
  int n,k,i,j;
  cin>>n>>k;
  if((n-1)/2<k){
    cout<<-1<<endl;
    return 0;
  }
  cout<<k*n<<endl;
  for(i=0;i<n;i++){
    for(j=0;j<k;j++){
      printf("%d %d\n",i%n+1,(i+1+j)%n+1);
    }
  }
  return 0;
}