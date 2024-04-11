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

int main(){
  int n;
  string str;
  cin>>n>>str;

  int i,ans=0;
  for(i=n;i<str.size();i+=n){
    ans+=(str[i-3]==str[i-2] && str[i-2]==str[i-1]);
  }
  cout<<ans<<endl;
  return 0;
}