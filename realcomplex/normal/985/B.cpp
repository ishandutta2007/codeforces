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

const int N = 2005;
int cnt[N];

int main(){
  fastIO;
  int n,m;
  cin >> n >> m;
  char c[n][m];
  for(int i = 0;i < n;i ++ ){
    for(int j = 0;j < m;j ++ ){
      cin >> c[i][j];
      if(c[i][j] == '1')
        cnt[j] ++ ;
    }
  }
  bool can;
  for(int i = 0;i < n;i ++ ){
    can = true;
    for(int j = 0;j < m;j ++ ){
      if(c[i][j] == '1' and cnt[j] <= 1)
        can = false;
    }
    if(can){
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}