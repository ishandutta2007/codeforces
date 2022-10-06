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
  int t,n,p,d;
  cin>>t;
  int i,j,sum;
  while(t--){
    cin>>n>>p;
    for(d=sum=0;sum<2*n+p&&d<n;d++){
      for(i=d+1;i<n&&sum<2*n+p;i++){
        cout<<d+1<<" "<<(i)%n+1<<endl;
        sum++;
      }
    }
    cout<<endl;
  }
  return 0;
}