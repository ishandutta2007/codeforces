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
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  int n,m;
  cin>>n>>m;
  vector<int> v(n);
  vector<vector<int>> cnt[n*n*n];
  iota(all(v),0);
  do{
    int sum=0;
    rep(i,n)rep(j,n-i)
      sum+=*min_element(v.begin()+i,v.begin()+i+j+1);
    cnt[sum].pb(v);
    //    cout<<v<<sum<<endl;
  }while(next_permutation(all(v)));
  int sum=0;
  rrep(i,n*n*n){
    if(cnt[i].size()){
      sort(all(cnt[i]));
      rep(j,n)
	cout<<cnt[i][m-1][j]+1<<" ";
      cout<<endl;
      break;
    }
    sum+=cnt[i].size();
  }
  return 0;
}