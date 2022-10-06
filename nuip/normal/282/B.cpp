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
  ll i,n,d=0;
  int a,g;
  vector<char> str;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>a>>g;
    if(abs(d+a)>abs(d-g)){
      d-=g;
      str.pb('G');
    }else{
      d+=a;
      str.pb('A');
    }
  }
  if(abs(d)>500){
    cout<<-1<<endl;
  }else{
    for(i=0;i<str.size();i++){
      cout<<str[i];
    }
    cout<<endl;
  }
  return 0;
}