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

int n,t,c,nums[212345];
multiset<int> mset;

int main(){
  int i,j,k,re=0;
  cin>>n>>t>>c;
  for(i=0;i<n;i++)
    cin>>nums[i];
  for(i=0;i<c-1;i++)
    mset.insert(nums[i]);
  for(;i<n;i++){
 //   cout<<i<<endl;
    mset.insert(nums[i]);
    if(*mset.rbegin()<=t)
      re++;
    mset.erase(mset.find(nums[i-c+1]));
  }
  cout<<re<<endl;
 // cout<<"!";
  return 0;
}