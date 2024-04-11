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
  vector<int> nums;
  int num,temp,i;
  scanf("%d",&num);

  for(i=0;i<num;i++){
    scanf("%d",&temp);
    nums.push_back(temp);
  }

  for(i=num-1;i>0;i--){
    if(nums[i-1]>=nums[i])
      break;
  }

  cout<<i<<endl;

  return 0;
}