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
  ll n,k,l,r,sum=0;
  int i;
  cin>>n>>k;
  for(i=0;i<n;i++){
    cin>>l>>r;
    sum+=(r-l)+1;
  }
  //cout<<sum<<endl;
  sum%=k;
  if(sum==0){
    cout<<0<<endl;
  }else{
    cout<<k-sum<<endl;
  }
  return 0;
}