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
#define rep(X,Y) for (int (X) = 0;(X) < int(Y);++(X))
#define rrep(X,Y) for (int (X) = int(Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < int(Y);++(X))
#define peat(X,Y) for (;(X) < int(Y);++(X))
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
  int i,j,k,INF=5000;
  int hpp,atkp,defp,hpm,atkm,defm,h,a,d;
  cin>>hpp>>atkp>>defp>>hpm>>atkm>>defm>>h>>a>>d;
  int re=1e6,hp,atk,def;
  rep(i,2000)rep(j,2000){
    int m,l=-1,r=INF,dp,dm;
    while(r-l>1){
      m=(r+l)/2;
      hp=hpp+i;
      atk=atkp+j;
      def=defp+m;
      dp=max(0,atkm-def);
      dm=max(0,atk-defm);
  //    if(i==99 && j==0)
  //      cout<<atkm<<","<<def<<"<"<<hp<<","<<dp<<":"<<hpm<<","<<dm<<endl;
      if(dp==0 || dm==0){
        if(dm!=0)
          r=m;
        else
          l=m;
        continue;
      }
      if( (hpm+dm-1)/dm < (hp+dp-1)/dp )
        r=m;
      else
        l=m;
    }
//    cout<<r<<endl;
    if(r<INF)re=min(i*h+j*a+r*d,re);
  }
  cout<<re<<endl;
  return 0;
}