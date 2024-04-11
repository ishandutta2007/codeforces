#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())

bool checker(ll x1, ll y1,ll x2, ll y2, ll x3 , ll y3){
  ll d1 = x1 - x2;
  ll d2 = y1 - y2;
  ll d3 = x2 - x3; 
  ll d4 = y2 - y3;
	return d2 * d3 == d1 * d4;
}

const int N = (int)1e5 + 111;
int n;
ll x[N];
ll y[N];

bool possible(int i,int j){
  int v1 = - 1,v2 = -1;
  for(int p = 0;p < n;p ++ ){
    if(i == p or j == p)
      continue;
    if(!checker(x[i],y[i],x[j],y[j],x[p],y[p])){
      if(v1 == -1){
        v1 = p;
      }
      else if(v2 == -1){
        v2 = p;
      }
      else{
        if(!checker(x[v1],y[v1],x[v2],y[v2],x[p],y[p])){
          return false;
        }
      }
    }
  }
  return true;
}

int main(){
  fastIO;
  cin >> n;
  if(n <= 4){
    cout << "YES\n";
    return 0;
  }
  for(int i = 0;i < n; i ++ ){
    cin >> x[i] >> y[i];
  }
  if(possible(0,1) or possible(1,2) or possible(0,2)){
    cout << "YES\n";
    return 0;
  }
  cout << "NO\n";
  return 0;
}