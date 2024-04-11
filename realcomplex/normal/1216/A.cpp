#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  int n;
  cin >> n;
  string t;
  cin >> t;
  int res = 0;
  for(int i = 0 ;i < n; i += 2){
    if(t[i] == t[i + 1]){
      res ++ ;
      if(t[i] == 'a') t[i] = 'b';
      else t[i] = 'a';
    }
  }
  cout << res << "\n" << t;
  return 0;
}