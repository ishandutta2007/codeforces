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


int digs[10];

int main(){
  vector<int> rem7[7];
  int nums[12]={1689,1698,1869,1896,1968,1986,6189,6198,6819,6891,6918,6981};
  int i,j,tmp,rem,inv[7]={0,1,4,5,2,3,6},pow10[6]={1,3,2,6,4,5};
  for(i=0;i<12;i++){
    rem7[nums[i]%7].pb(nums[i]);
  }

  char c;
  while(scanf("%c",&c)!=EOF){
    if(c=='-'){
      printf("-");
      continue;
    }
    if(c<'0' || '9'<c)
      break;
    digs[c-'0']++;
  }
  digs[1]--;
  digs[6]--;
  digs[8]--;
  digs[9]--;
  rem=0;
  for(i=1;i<=9;i++){
    for(j=0;j<digs[i];j++){
      rem=(rem*10+i)%7;
      printf("%d",i);
    }
  }
  rem=(rem*pow10[4])%7;
  rem=((7-rem)%7);//*inv[pow10[digs[0]%7]]%7;
  printf("%d",rem7[rem%7][0]);
  for(i=0;i<digs[0];i++)
    printf("0");
  printf("\n");
  return 0;
}