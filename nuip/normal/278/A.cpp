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

using namespace std;
typedef __int64 ll;

int main(){
  long sum=0,all=0;
  vector<int> d;
  int n,s,t,begint,endt;

  cin>>n;
  int temp;
  for(int i=0;i<n;i++){
    cin>>temp;
    all+=temp;
    d.push_back(temp);
  }
  cin>>s>>t;
  begint=min(s,t);
  endt=max(s,t);

  for(int i=begint;i<endt;i++){
    sum+=d.at(i-1);
    all-=d.at(i-1);
  }
  cout<<min(sum,all)<<endl;
  return 0;
}