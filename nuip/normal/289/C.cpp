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
  ll n,k,i,j;
  char str[1000005];
  cin>>n>>k;
  str[n]='\0';
  if(k==1){
    if(n==1){
      cout<<"a"<<endl;
    }else{
      cout<<-1<<endl;
    }
  }else if(n<k){
    cout<<-1<<endl;
  }else{
    for(i=1;i<k-1;i++){
      str[n-i]='a'+(k-i);
    }
    for(j=0;j<=n-i;j++){
      str[j]=( (j%2)?'b':'a');
    }
    cout<<str<<endl;
  }
  return 0;
}