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

map<string,string>seen;

int main(){
  fastIO;
  seen["purple"] = "Power";
  seen["green"] = "Time";
  seen["blue"] = "Space";
  seen["red"] = "Reality";
  seen["orange"] = "Soul";
  seen["yellow"] = "Mind";
  int n;
  cin >> n;
  int sz = 6-n;
  string s;
  for(int i = 0;i < n;i ++ ){
    cin >> s;
    seen[s].erase();
  }
  cout << sz << "\n";
  for(auto x : seen)
    cout << x.se << "\n";
  return 0;
}