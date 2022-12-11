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

bool palin(string x){
  int n = x.size();
  for(int i = 0;i < n;i ++ )
    if(x[i] != x[n - i - 1])
      return false;
  return true;
}

int main(){
  fastIO;
  string s;
  cin >> s;
  int n = s.size();
  int ans = 0;
  for(int i = 0;i < n;i ++ ){
    for(int j = 1;j + i <= n; j ++ )
      if(!palin(s.substr(i,j)))
        ans = max(ans, j);
  }
  cout << ans << "\n";
  return 0;
}