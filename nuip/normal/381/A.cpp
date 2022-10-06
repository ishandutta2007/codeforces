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
#define all(X) (X).begin(),(X).end()

using namespace std;
typedef __int64 ll;


int main(){
  int n,i,j;
  scanf("%d",&n);
  vector<int> nums(n);
  for(i=0;i<n;i++){
    scanf("%d",&nums[i]);
  }
  int l=0,r=n-1,score[2]={0,0};
  i=0;
  while(l<=r){
    if(nums[l]>nums[r]){
      score[(i++)%2]+=nums[l++];
    }else{
      score[(i++)%2]+=nums[r--];
    }
  }
  cout<<score[0]<<" "<<score[1]<<endl;
  return 0;
}