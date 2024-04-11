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
#define rrep(X,Y) for (int (X) = (Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

const int MAX_N=(1<<18);
const ll INF=(1ll<<60);
int nn=MAX_N;

struct Mx{
  pll mx,mx2;
  Mx(ll d=-INF,ll D=-INF,int i=100000,int j=100000){
    mx=pll(d,i);
    mx2=pll(D,j);
  }
  static Mx e;
};
vector<Mx> datmx(2*MAX_N-1);
Mx Mx::e=Mx();
struct Mn{
  pll mn,mn2;
  Mn(ll d=INF,ll D=INF,int i=100000,int j=100000){
    mn=pll(d,i);
    mn2=pll(D,j);
  }
  static Mn e;
};
vector<Mn> datmn(2*MAX_N-1);
Mn Mn::e=Mn();

Mx operator+(Mx l,Mx r){
  if(l.mx<r.mx)
    swap(l,r);
  if(l.mx2<r.mx)
    l.mx2=r.mx;
  return l;
}
Mn operator+(Mn l,Mn r){
  if(l.mn>r.mn)
    swap(l,r);
  if(l.mn2>r.mn)
    l.mn2=r.mn;
  return l;
}

template<class T> void upd(vector<T> &dat,int k,T a){
  k+=nn-1;
  dat[k]=a;
  while(k>0){
    k=(k-1)/2;
    dat[k]=dat[k*2+1]+dat[k*2+2];
  }
}

//(l,r,0,0,nn)
template<class T> T query(vector<T> &dat,int a,int b,int k,int l,int r){
  if(r<=a || b<=l)return T::e;
  if(a<=l && r<=b) return dat[k];
  return query(dat,a,b,k*2+1,l,(l+r)/2) + query(dat,a,b,k*2+2,(l+r)/2,r);
}
int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k,n,m;
  scanf("%d %d",&n,&m);
  vector<int> d(n),h(n);
  rep(i,n)
    scanf("%I64d",&d[i]);
  rep(i,n)
    scanf("%I64d",&h[i]);
  ll sum=0;
  rep(i,2*n){
    upd(datmn,i,Mn(sum-h[i%n]*2,INF,i%n));
    upd(datmx,i,Mx(sum+h[i%n]*2,-INF,i%n));
    sum+=d[i%n];
  }
  int a,b;
  rep(i,m){
    scanf("%d %d",&a,&b);
    --a,--b;
    if(a<=b){
      b++;
      a+=n;
    }else{
      b++;
    }
    Mn mn=query(datmn,b,a,0,0,nn);
    Mx mx=query(datmx,b,a,0,0,nn);
    /*  cout<<b<<","<<a<<endl;
    cout<<mn.mn<<mn.mn2<<endl;
    cout<<mx.mx<<mx.mx2<<endl;*/
    if(mn.mn.Y!=mx.mx.Y){
      printf("%I64d\n",mx.mx.X-mn.mn.X);
    }else{
      printf("%I64d\n",max(mx.mx.X-mn.mn2.X,
			 mx.mx2.X-mn.mn.X));
    }      
  }
  return 0;
}