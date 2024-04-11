#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <bitset>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#include <tuple>

using namespace std;

#define ll long long
#define ull unsigned long long

#define FOR(i, n) for(ll i = 0; i < (n); ++i)
#define FORU(i, j, k) for(ll i = j; i <= (k); ++i)
#define FORD(i, j, k) for(ll i = j; i >= (k); --i)

#define pf push_front
#define pb push_back

#define mp make_pair
#define f first
#define s second

bool solve(string& s, char p, ll i){
  if(i == 0){
    if(s[0] + 1 >= p){
      return false;
    }else{
      s[0] += 1;
      return true;
    }
  }else if(i == 1){
    if(s[1] + 1 >= p || (s[1] + 1 == s[0] && s[1] + 2 >= p)){
      if(solve(s, p, 0)){
        s[1] = 'a';
        return true;
      }else{
        return false;
      }
    }else if(s[1] + 1 == s[0]){
      s[1] += 2;
      return true;
    }else{
      s[1] += 1;
      return true;
    }
  }else{
    if(s[i] + 1 >= p
    || ((s[i] + 1 == s[i-1] || s[i] + 1 == s[i-2]) && s[i] + 2 >= p)
    || (((s[i] + 1 == s[i-1] && s[i] + 2 == s[i-2])
        || (s[i] + 2 == s[i-1] && s[i] + 1 == s[i-2])
        ) && s[i] + 3 >= p)
    ){
      if(solve(s, p, i-1)){
        s[i] = 'a';
        while(s[i] < p && (s[i] == s[i-1] || s[i] == s[i-2])){
          s[i] += 1;
        }
        return s[i] < p;
      }else{
        return false;
      }
    }else{
      s[i] += 1;
      while(s[i] < p && (s[i] == s[i-1] || s[i] == s[i-2])){
        s[i] += 1;
      }
      return true;
    }
  }
}

int main(int, char**){
  ios::sync_with_stdio(false);
  ll n, p; cin >> n >> p;
  string s; cin >> s;
  if(solve(s, 'a'+p, s.size()-1)){
    cout << s << endl;
  }else{
    cout << "NO\n";
  }
  return 0;
}