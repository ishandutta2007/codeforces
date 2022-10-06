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


long long memo[100];

int ff(long long n){
  int re=1;
  while(n!=1){
    if(n%2==1){
      re++;
      n--;
    }
    n/=2;
  }
  return re;
}


int main(){
  memo[0]=0;
  for(int i=1;i<100;i++){
    memo[i]=0;
  }
  
  int num;
  long long temp;
  cin>>num;
  for(int i=0;i<num;i++){
    cin>>temp;
    memo[ff(temp)]++;
  }
  long long re=0;
  for(int i=0;i<100;i++){
    if(memo[i]>1)
      re+=(memo[i])*(memo[i]-1)/2;
  }
  cout<<re<<endl;
  return 0;
}