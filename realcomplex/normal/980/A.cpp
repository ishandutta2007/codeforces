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

int main(){
  fastIO;
  string s;
  cin >> s;
  int v = 0, vv = 0;
  for(char x : s){
    if(x == 'o')
      v ++ ;
    else
      vv ++ ;
  }
  if(vv == 0 or v == 0)
    cout << "YES\n";
  else if(vv % v == 0)  
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}