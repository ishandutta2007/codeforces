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

int zero(string str){
  ll i;
  bool re=0;
  for(i=0;i<str.size();i++){
    re|=(str[i]=='1');
  }
  return re;
}
int main(){
  string a,b;
  cin>>a;
  cin>>b;
  if(a.size()!=b.size()){
    cout<<"NO"<<endl;
  }else if(zero(a)!=zero(b)){
    cout<<"NO"<<endl;
  }else{
    cout<<"YES"<<endl;
  }
  return 0;
}