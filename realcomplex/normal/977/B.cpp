#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

int main(){
  fastIO;
  int n;
  cin >> n;
  string s;
  cin >> s;
  string ans = "";
  int t = 0;
  string cur;
  int cnt;
  for(int i = 0;i < n - 1; i ++ ){
    cur.clear();
    cur += s[i];
    cur += s[i + 1];
    cnt = 0;
    for(int i = 0;i < n - 1;i ++ ){
      if(s.substr(i,2) == cur)
        cnt++;
    } 
    if(cnt > t)
      t = cnt,ans = cur;
  }
  cout << ans;
  return 0;
}