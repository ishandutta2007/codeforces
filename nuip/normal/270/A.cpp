#line 89 "BallsSeparating.cpp"
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

using namespace std;

int main(){
  int num,a;
  scanf("%d",&num);

  for(int i=0;i<num;i++){
    scanf("%d",&a);
    if(a>=180){
      cout<<"NO"<<endl;
      continue;
    }
    cout<<((360%(180-a)==0)?"YES":"NO")<<endl;
  }

  return 0;
}