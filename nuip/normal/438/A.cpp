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
typedef long long ll;


int main(){
  int i,j,k;
  int n,m,a[1123],c,b,re=0;
  cin>>n>>m;
  for(i=0;i<n;i++)
    cin>>a[i+1];
  for(i=0;i<m;i++){
    cin>>c>>b;
    re+=min(a[c],a[b]);
  }
  cout<<re<<endl;
  return 0;
}