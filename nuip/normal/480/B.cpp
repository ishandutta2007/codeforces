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

vector<pii> serch(int n,vector<int> &v){
  int l,r,sum;
  vector<pii> re;
  l=r=0;
//  cout<<n<<":";
  while(r<v.size()){
    sum=v[r]-v[l];
//    cout<<"["<<l<<","<<r<<","<<sum<<"]";
    if(sum==n)
      re.pb(pii(l,r));
    if(sum<n){
      r++;
    }else{
      l++;
    }
  }//cout<<endl;
  return re;
}

int main(){
  std::ios_base::sync_with_stdio(false);
  int i,j,k,n,l,x,y;
  cin>>n>>l>>x>>y;
  vector<int> v(n);
  rep(i,n)
    cin>>v[i];
  vector<pii> xx,yy,pl,mn;
  xx=serch(x,v);
  yy=serch(y,v);
  pl=serch(x+y,v);
  mn=serch(y-x,v);
  if(xx.size()==0){
    if(yy.size()==0){
      if(pl.size()>0){
        cout<<1<<endl<<v[pl[0].X]+x<<endl;
        return 0;
      }
      int ans=-1;
      rep(i,mn.size())
        if(0<=v[mn[i].X]-x){
          ans=v[mn[i].X]-x;
        }else if(v[mn[i].Y]+x<=l){
          ans=v[mn[i].Y]+x;
        }
      if(ans<0)
        cout<<2<<endl<<x<<" "<<y<<endl;
      else
        cout<<1<<endl<<ans<<endl;
    }else{
      cout<<1<<endl<<x<<endl;
      return 0;
    }
  }else{
    if(yy.size()==0){
      cout<<1<<endl<<y<<endl;
      return 0;
    }else{
      cout<<0<<endl;
      return 0;
    }
  }
  return 0;
}