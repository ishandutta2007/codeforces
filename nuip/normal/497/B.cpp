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

vector<int> st[2][112345];
int sum[2][112345];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  int n,INF=1e7;
  cin>>n;
  vector<int> a(n);
  rep(i,n)
    cin>>a[i];
  rep(i,n){
    rep(j,2)
      sum[j][i+1]=sum[j][i];
    sum[a[i]-1][i+1]++;
  }
  rep(i,n+1)
    rep(j,2)
    st[j][sum[j][i]].pb(i);
  rep(i,112345)
    rep(j,2)
      st[j][i].pb(INF);
//  rep(j,2){rep(i,3)cout<<st[j][i-1];cout<<endl;}
//  rep(i,5)cout<<89878-i<<":"<<st[0][89876+2-i];
  vector<pii> re;
  for(int s=1;s<=n;s++){
    int last=0,cnt=0,d=0;
 //   cout<<"["<<s<<"]"<<endl;
    for(;;cnt++){
      int aw=sum[0][last]+s,bw=sum[1][last]+s;
      if(max(aw,bw)>n)break;
      int al=*lower_bound(all(st[0][aw]),last),
          bl=*lower_bound(all(st[1][bw]),last);
      if(al<bl){
        d++;
        last=al;
      }else{
        d--;
        last=bl;
      }
 //    cout<<al<<","<<bl<<","<<d<<","<<last<<","<<aw<<","<<bw<<endl;
      if(last>n){
        break;
      }else if(last==n){
        if(1ll*d*(bl-al)>0)re.pb(pii((cnt+1+abs(d))/2,s));
        break;
      }
    }
  }
  sort(all(re));
  cout<<re.size()<<endl;
  rep(i,re.size())
    cout<<re[i].X<<" "<<re[i].Y<<endl;
  return 0;
}