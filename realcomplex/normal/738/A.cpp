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
  int p = 0;
  int x = s.size();
  while(p < (int)s.size()){
    if(x >= 3){
      if(s[p] == 'o' and s[p + 1] == 'g' and s[p + 2] == 'o'){
        cout << "***";
        x -= 3;
        p += 3;
        while(x >= 2){
          if(s[p] == 'g' and s[p + 1] == 'o')
            p += 2, x -= 2;
          else{
            break;
          }
        }
      }
      else{
        x--;
        cout << s[p];
        p++;
      }
    }
    else{
      cout << s[p];
      p++;
    }
  }
  return 0;
}