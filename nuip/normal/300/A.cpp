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

vector<int> nega,posi;
int n,zero;

int main(){
  scanf("%d",&n);
  int i,temp,hoge;
  zero=0;
  for(i=0;i<n;i++){
    scanf("%d",&temp);
    if(temp>0){
      posi.push_back(temp);
    }else if(temp<0){
      nega.push_back(temp);
    }else{
      zero++;
    }
    //cout<<"!"<<temp<<endl;
  }
  int negaS=0;
  if(posi.empty()){
    negaS=2;
    posi.push_back(nega.at(0));
    posi.push_back(nega.at(1));
  }
  if((nega.size())%2==0){
    hoge=nega.at(negaS);
    negaS++;
  }
  printf("%d",nega.size()-negaS);
  for(i=negaS;i<nega.size();i++){
    printf(" %d",nega.at(i));
  }
  printf("\n");
  printf("%d",posi.size());
  for(i=0;i<posi.size();i++){
    printf(" %d",posi.at(i));
  }
  printf("\n");
  printf("%d",zero+(negaS%2));
  if(negaS%2)
    printf(" %d",hoge);
  for(i=0;i<zero;i++){
    printf(" 0");
  }
  printf("\n");
  return 0;
}