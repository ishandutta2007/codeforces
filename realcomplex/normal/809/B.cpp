#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))
#define all(a) a.begin(), a.end()
#define ones(a) __builtin_popcount(a)

bool query(int x, int y){
  if(x < 0 or x == y)
    return false;
  cout << 1 << " " << x << " " << y << endl;
  fflush(stdout);
  string s;
  cin >> s;
  if(s == "NIE")
    return false;
  return true;
}

int search(int l, int r){
  if(l > r)
    return -1;
  int mid;
  while(l < r){
    mid = (l + r)/2;
    if(query(mid, mid + 1)){
      r = mid;
    }
    else{
      l = mid + 1;
    }
  }
  return l;
}

int main(){
  fastIO;
  int n,k;
  cin >> n >> k;
  int v1 = search(1, n);
  int v2 = search(1, v1-1);
  if(query(v2, v1)){
    cout << 2 << " " << v1 << " " << v2 << "\n";
    return 0;
  }
  v2 = search(v1+1, n);
  cout << 2 << " " << v1 << " " << v2 << "\n";
  return 0;
}