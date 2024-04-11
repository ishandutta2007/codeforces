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
typedef pair<int,int> P;

vector<P> people;
vector<int> rates(312345);

int main(){
  int n,i,j,tmp;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&tmp);
    people.pb(P(tmp,i));
  }
  sort(people.begin(),people.end());

  int pre=0,out;
  for(i=0;i<n;i++){
  //  cout<<pre<<",";
    out=people[i].X;
    while(pre>=out)
      out++;
    rates[people[i].Y]=pre=out;
  }
  for(i=0;i<n;i++){
    printf("%d%c",rates[i],(i==n-1)?'\n':' ');
  }
  return 0;
}