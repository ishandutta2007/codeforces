#include<bits/stdc++.h>
#define X first
#define Y second
#define pb emplace_back
#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define EFOR(i,a,b) for(int (i)=(a);i<=(b);++(i))
#define rep(X,Y) for(int (X)=(0);(X)<(Y);++(X))
#define REP rep
#define rrep(X,Y) for(int (X)=(Y)-1;(X)>=0;++(X))
#define all(x) (x).begin(),(x).end()
#define eb pb

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef ll LL;
typedef pii PII;
typedef pll PLL;
const ll MOD=1e9+7;

#define rall(X) (X).rbegin(),(X).rend()
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define reps(X,S,Y) for(int (X)=S;(X)<(Y);++(X))
#define rreps(X,S,Y) for(int (X)=(Y)-1;(X)>=(S);--(X))

template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
const int SIZE=3e5;
LL A[SIZE];
LL n,m,t;
LL f(LL d){
  int cof=0;
  LL used=0;
  LL ans=0;
  LL coft=0;
  REP(i,n){
    if(A[i]>d) continue;
    used+=A[i];
    coft+=A[i];
    if(used>t) return ans;
    ans++;
    cof++;
    if(cof==m){
      used+=coft;
      coft=0;
      cof=0;
    }
  }
  return ans;
}
LL fable(LL d){
  int cof=0;
  LL used=0;
  LL ans=0;
  LL coft=0;
  REP(i,n){
    if(A[i]>d) continue;
    used+=A[i];
    coft+=A[i];
    if(used>t) return 0;
    ans++;
    cof++;
    if(cof==m){
      used+=coft;
      coft=0;
      cof=0;
    }
  }
  return 1;
}

int main(){
  int test;
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(0);

  cin >> test;
  REP(k,test){
    LL answer=0;
    cin >> n >> m >> t;
    REP(i,n) cin >> A[i];
    LL s=0,e=3e5;
    while(s<=e){
      int f=(s+e)/2;
      if(fable(f)){
	s=f+1;
      }else{
	e=f-1;
      }
    }
    if(f(s)<f(e)){
      answer=e;
    }else{
      answer=s;
    }
    /*  while(e-s>10){
      int f1=(e-s)/3+s;
      int f2=(e-s)*2/3+s;
      if(f(f1)<f(f2)){
	s=f1;
      }else{
	e=f2;
      }
      //   cout << f(f1) << " " << f(f2) << " f" << endl;
      //
      //cout << s <<"  " << e <<endl;
      }*/
    
    /*   LL answer=s;
    EFOR(i,s,e){
      if(f(answer)<f(i)){
	answer=i;
      }
      }*/
    
    answer=min(t,max(1LL,answer));
    //    e=min(t,max(1LL,e));
    //if(f(s)<f(e)){
    cout <<f(answer) << " " << min(t,max(1LL,answer)) << endl;
      //}else{
      //cout <<f(s) << " " << min(t,max(1LL,s)) << endl;
 
      //}
  }
  
  return 0;
}