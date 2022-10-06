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

int N,a[1123];
map<int,queue<int> > re;
map<int,queue<int> >::reverse_iterator rit;

int main(){
  int i,j,k,p=0,sum=0;
  cin>>N;
  for(i=0;i<N;i++){
    cin>>a[i];
    for(j=0;j<a[i];j++){
      if(j)i%2?p--:p++;
      re[p].push(i%2?-sum:sum);
      sum++;
    }
  }//cout<<sum<<endl;
  for(rit=re.rbegin();rit!=re.rend();rit++){
    if(rit!=re.rbegin())printf("\n",rit->X);
    for(i=0;i<sum;i++){
      if(i==rit->Y.front()){
        printf("/");//cout<<rit->Y.front()<<endl;
        rit->Y.pop();
      }else if(i==-rit->Y.front()){
        printf("\\");//cout<<rit->Y.front()<<endl;
        rit->Y.pop();
      }else{
        printf(" ");
      }
    }
  }
  return 0;
}