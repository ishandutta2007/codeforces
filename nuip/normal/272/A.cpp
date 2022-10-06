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

using namespace std;

int main(){
  int n,sum=0,ans=0;
  cin>>n;

  int temp;
  for(int i=0;i<n;i++){
    cin>>temp;
    sum+=temp;
    sum%=n+1;
  }
  for(int i=1;i<=5;i++){
    ans+=((sum+i)%(n+1)!=1);
  }
  cout<<ans<<endl;
  return 0;
}