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

struct SEG{
  int segment_length;
  char chars;
};

int main(){
  fastIO;
  string s;
  cin >> s;
  SEG cur;
  vector<SEG>st;
  cur.segment_length = 0;
  cur.chars = '-';
  for(char x : s){
    if(x == cur.chars){
      cur.segment_length++;
    } 
    else{
      if(cur.segment_length > 0)st.push_back(cur);
      cur.segment_length=1;
      cur.chars = x;
    }
  }
  st.push_back(cur);
  int ans = 0;
  int p;
  while(len(st) > 1){
    vector<SEG>effect;
    for(int x = 0;x<len(st);x++){
      cur = st[x];
      if(x == 0 or x == len(st)-1){
        cur.segment_length -- ; // one element to remove
      }
      else{
        cur.segment_length -= 2; // two elements to remove
      }
      if(cur.segment_length <= 0){
        continue; // segment gone
      }
      if(effect.empty()){
        effect.push_back(cur);
      }
      else{
        if(effect.back().chars == cur.chars){
          effect.back().segment_length += cur.segment_length;
        }
        else{
          effect.push_back(cur);
        }
      }
    }
    st = effect;
    ans++;
  } 
  cout << ans;
  return 0;
}