#pragma optimize ("O3")
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
#define len(x) ((int)(x).size())

int main(){
  fastIO;
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt = 0;
  int iq = 0;
  int x1 = 0,x2 = 0;
  int p = 0;
  for(auto x : s){
    if(x == '_' or x == '(' or x == ')'){
      cnt = 0;
      if(x == '(')
        iq++;
      else if(x == ')')
        iq--;
    }
    else{
      if(iq > 0){
        if(p == 0)
          x2++;
        else{
          if(s[p-1] == '_' or s[p-1] == '(')
            x2 ++ ;
        }
      }
      cnt++;
    }
    if(iq == 0)
      x1 = max(x1, cnt);
    ++p;
  }
  cout << x1 << " " << x2;
  return 0;
}