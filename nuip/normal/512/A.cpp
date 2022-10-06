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

vector<vector<int>> G(26,vector<int>(26));

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  int n;
  cin>>n;
  vector<string> strs(n);
  rep(i,n)
    cin>>strs[i];
  rep(i,n-1)rep(j,min(strs[i].size(),strs[i+1].size())){
    if(strs[i].substr(0,j)==strs[i+1].substr(0,j)
 && strs[i][j]!=strs[i+1][j]){
      G[strs[i][j]-'a'][strs[i+1][j]-'a']=1;
      //     cout<<strs[i][j]<<"->"<<strs[i+1][j]<<endl;
    }
  }
  //  cout<<G<<endl;
  vector<int> used(26);
  string re;
  rep(i,26){
    int nf=1;
    rep(j,26)if(!used[j]){
      int f=0;
      rep(k,26){
	if(G[k][j]==1)
	  f=1;
      }
      if(!f){
	re+=char(j+'a');
	//	cout<<re<<endl;
	used[j]=1;
	rep(k,26)
	  G[j][k]=0;
	nf=0;
	break;
      }
    }
    if(nf){
      cout<<"Impossible"<<endl;
      return 0;
    }
  }
  rep(i,n-1){
    if(strs[i].size()>strs[i+1].size()){
      if(strs[i].substr(0,strs[i+1].size())==strs[i+1]){
	cout<<"Impossible"<<endl;
	return 0;
      }
    }
  }
  cout<<(re.size()==26?re:"Impossible")<<endl;
  return 0;
}