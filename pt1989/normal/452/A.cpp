#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex> 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

#define sf(n)         scanf("%lf",&n)
#define fill(a,v)     memset(a, v, sizeof a)
#define bitcount      __builtin_popcount
#define all(x)        x.begin(), x.end()
#define pb(z)       push_back( z )
#define gcd           __gcd

bool isNum(char c) { return ('0' <= c && c <= '9'); }
template<typename T>
T read(T &res) {
  res = 0; char c, neg = 0;
  do { c=getchar(); } while (!isNum(c) && c != '-');
  if (c == '-') { neg = 1; c = getchar(); }
  while (isNum(c)) { res = res * 10 + c-'0'; c = getchar(); }
  return neg ? -res : res;
}

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

#define readInt read<int>
#define readLL read<ll>




int main() {
  string poke[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
  int poke_count = 8;
  int n;
  string pat;
  cin>> n >> pat;  
  for (int i=0; i < poke_count; i++) {
    string txt = poke[i];
    if (pat.length() == txt.length()) {
      bool match = true;
      for (int i=pat.length()-1; i >= 0; i--) {
        if (txt[i] == pat[i] || pat[i] == '.') {
          
        } else {
          match = false;
        }
      }
      if (match) {
        cout << txt << endl; break;
      }
    }
  }
  
}