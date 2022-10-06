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
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
  int i,j,k;
  int n,h,f=0;
  cin>>n;
  vector<int> cnt[2123];
  rep(i,n){
    cin>>h;
    if(cnt[h].size())
      f++;
    cnt[h].pb(i);
  }
  if(f>=2){
    cout<<"YES"<<endl;
    f=0;
    rep(i,3){
      rep(j,2123){
        if(cnt[j].size()>1){
          if(f==0 && i==1){
            f=1;
            next_permutation(all(cnt[j]));
          }else if(f==1 && i==2){
            next_permutation(all(cnt[j]));
          }
        }
        rep(k,cnt[j].size())
          cout<<cnt[j][k]+1<<" ";
      }
      cout<<endl;
    }
  }else{
    cout<<"NO"<<endl;
  }
  return 0;
}