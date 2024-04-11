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

int n,a[112345];
char c;

int main(){
  scanf("%d",&n);
  int i,j,sum0=0,sum=0;

  for(i=0;i<n;i++){
    scanf("%d",a+i);
  }

  for(i=0;i<n;i++){
    while(!isdigit(c=getchar()));
    if(c=='0'){
      sum0+=a[i];
    }else{
      sum+=max(sum0,a[i]);
      sum0=min(sum0,a[i]);
    }
   // cout<<sum<<","<<sum0<<endl;
  }
  cout<<sum<<endl;
  return 0;
}