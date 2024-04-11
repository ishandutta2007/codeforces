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
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S,class T> ostream& operator<<(ostream &os, const map<S,T> &t) {
  os<<"{"; for(auto p:t) {os<<p<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
typedef pair<int,pii> piii;
int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,q;
  scanf("%d%d",&n,&q);
  //  cin>>n>>q;
  map<int,piii> mp;
  mp[0]=piii(n,pii(0,0));
  int x,y;
  char c;
  rep(i,q){
    scanf("%d %d %c",&x,&y,&c);//    cin>>x>>y>>c;
    //printf("%d%d%c\n",x,y,c);
    --x; --y;
    auto it=mp.upper_bound(x);
    --it;
    if(x<it->X || it->Y.X<=x){
      printf("0\n");
      continue;
    }
    if(c=='L'){
      printf("%d\n",x- it->X + it->Y.Y.X +1);
      piii tmp=it->Y;
      it->Y.X=x;
      it->Y.Y.Y=0;
      tmp.Y.X=x- it->X + it->Y.Y.X + 1;
      mp[x+1]=tmp;
    }else{
      piii tmp=it->Y;
      printf("%d\n",tmp.X - x + tmp.Y.Y);
      it->Y.X=x;
      it->Y.Y.Y=tmp.X - x + tmp.Y.Y;
      tmp.Y.X=0;
      mp[x+1]=tmp;
    }
    //cout<<mp<<endl;
  }
  return 0;
}