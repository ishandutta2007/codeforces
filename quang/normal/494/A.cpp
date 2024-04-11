#include <bits/stdc++.h>
#define Task "A"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

string s;

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  cin >> s;
  int slmo = 0, sldong = 0,slthay = 0, vt;
  for(int i = 0; i < s.size(); i++) {
    slmo += (s[i] == '(');
    sldong += (s[i] == ')');
    slthay += (s[i] == '#');
    if(s[i] == '#')
      vt = i;
  }
  int need = slmo - sldong;
  if(need < slthay) {
    cout << -1;
    return 0;
  }
  slmo = sldong = 0;
  stringstream ans;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == '(') slmo++;
    if(s[i] == ')') sldong++;
    if(s[i] == '#') {
      if(vt == i) {
        ans << need << " ";
        sldong += need;
      }
      else  {
        ans << 1 << " ";
        sldong++;
        need--;
      }
    }
    if(slmo < sldong) {
      cout <<  -1;
      return 0;
    }
  }
  cout << ans.str();
  return 0;
}