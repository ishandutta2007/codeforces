#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 9;
const int AL = 26;
bool win[AL];
int who[N];

int main(){
  fastIO;
  string t;
  cin >> t;
  int idx = 0;
  for(char x : t){
    if(win[x - 'a']){
      who[idx] = true;
    }
    else{
      for(int j = x - 'a' + 1; j < AL ;j ++ )
        win[j] = true;
    }
    idx ++ ;
  }
  for(int j = 0 ; j < (int)t.size(); j ++ )
    if(who[j]) cout << "Ann\n";
    else cout << "Mike\n";
  return 0;
}