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
  cout<<fixed<<setprecision(10);
  int i,j,k;
  int n,n3[]={1,3,9,27,81,243},INF=1e7;
  double re=0;
  cin>>n;
  vector<int> l(n),r(n);
  //  cout<<n<<endl;
  rep(i,n){
    cin>>l[i]>>r[i];
  }
  rep(i,n3[n]){
    int L[2]={-INF,-INF},R[2]={INF,INF},tmp,cnt[2]={},flag=0;
    //   rep(j,n)cout<<i/n3[j]%3<<" ";cout<<endl;
    rep(j,n)if(tmp=i/n3[j]%3){
      L[tmp-1]=max(L[tmp-1],l[j]);
      R[tmp-1]=min(R[tmp-1],r[j]);
      cnt[tmp-1]++;
    }
    if(cnt[0]==0 || cnt[1]>1)
      continue;
    if(cnt[1]==0){
      if(cnt[0]==1)
	continue;
      R[1]=-1;
      L[1]=1;
      flag=1;
    }
    //  rep(j,2)cout<<"["<<L[j]<<","<<R[j]<<"]";
    double low=1;
    for(j=L[0];j<=R[0];j++){
      low=1;
      rep(k,n)if(!(i/n3[k]%3)){
	low*=max(0,min(r[k]+1,j)-l[k]);
      }
      re+=low*(flag?1:max(0,R[1]-max(L[1]-1,j)))*j;
    }
    //  cout<<re<<endl;
  }
  rep(i,n)
    re/=r[i]-l[i]+1;
  cout<<re<<endl;
  return 0;
}