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


int main(){
  vector<int> a;
  int tmp,sum=0,i,j,n,m,d;
  cin>>n>>d;
  for(i=0;i<n;i++){
    cin>>tmp;
    a.pb(tmp);
  }
  cin>>m;
  sort(a.begin(),a.end());
  for(i=0;i<min(n,m);i++){
    sum+=a[i];
  }
  if(n<m)
    sum-=d*(m-n);
  cout<<sum<<endl;
  return 0;
}