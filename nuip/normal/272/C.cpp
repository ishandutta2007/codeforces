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
  int num;
  long long temp;
  vector<long long> stairs;
  cin>>num;
  for(int i=0;i<num;i++){
    cin>>temp;
    stairs.push_back(temp);
  }

  long long floor=0;
  long long boxN,x,y;
  cin>>boxN;
  for(int i=0;i<boxN;i++){
    cin>>x;
    cin>>y;
    long long outN;
    outN=max(stairs[x-1],floor);
    floor=outN+y;
    cout<<outN<<endl;
  }
  return 0;
}