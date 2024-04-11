#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int k;

struct IT{
  vector<int> low;
  vector<int> high;
  int sz;
  bool operator< (const IT &T) const {
    for(int i = 0 ; i < k ; i ++ )
      if(high[i] > T.low[i])
        return false;
    return true;
  }
};  

IT unite(IT A, IT B){
  IT C = A;
  C.sz += B.sz;
  for(int i = 0 ; i < k ; i ++ ){
    C.low[i] = min(A.low[i], B.low[i]); 
    C.high[i] = max(A.high[i], B.high[i]);
  }    
  return C;
}

bool check(IT A, IT B){ 
  for(int i = 0 ; i < k ; i ++ ){
    if(B.low[i] < A.high[i]){
      return true;
    }
  }
  return false;
}

int main(){
  fastIO;
  int n;
  cin >> n >> k;
  set<IT> els;
  int x;
  for(int i = 0 ; i < n ; i ++ ){
    IT cur = {{},{},1};
    for(int j = 0 ; j < k ; j ++ ){
      cin >> x;
      cur.low.push_back(x);
      cur.high.push_back(x);
    }
    auto it = els.lower_bound(cur);
    while(it != els.end()){
      if(check(cur, *it)){
        cur = unite(cur, *it);
        els.erase(it);
        it = els.lower_bound(cur);
      }
      else{
        break;
      }
    }
    els.insert(cur);
    auto p = els.end();
    --p;
    cout << p->sz << "\n";
  }
  return 0;
}