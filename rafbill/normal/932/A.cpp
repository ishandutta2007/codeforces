#include <bits/stdc++.h>

#define FOR(i, n)     for(int i = 0; i < (int)(n); ++i)
#define FORU(i, j, k) for(int i = (j); i <= (int)(k); ++i)
#define FORD(i, j, k) for(int i = (j); i >= (int)(k); --i)

#define all(x) begin(x), end(x)

using namespace std;

//------------------------------------------------------------------------------

// Palindromic tree
// 0 is the odd palindrome with size -1, 1 is the empty even palindrome

const int N = 1e6+3;

map<int,int> to[N]; // Children
int link[N];        // Parent
int diff[N];        // Length difference with the parent
int slink[N];       // Link to the first parent of a different series
                    // A series is a sequence of palindrome with constant size difference
                    // The path to the root through slink has size O(log n)
int len[N];         // Node palindrome length
int last[N];        // Nodes of prefixes of s
int n, m;           // String size, tree size
int s[N];           // String

void init() {
  link[0] = link[1] = 0;
  last[0] = 0;
  len[0] = -1; len[1] = 0;
  diff[0] = diff[1] = -1;
  slink[0] = slink[1] = -1;
  n = 0; m = 2;
}

void add(int x) {
  s[n] = x; n += 1;
  last[n] = last[n-1];
  for(;;last[n] = link[last[n]]) {
    if(s[n-2-len[last[n]]] == x) {
      if(!to[last[n]].count(x)) {
        int v = m; m++;
        to[last[n]][x] = v;
        len[v] = len[last[n]]+2;
        if(len[v] == 1) {
          link[v] = 1;
        } else {
          link[v] = link[last[n]];
          while(s[n-2-len[link[v]]] != x) link[v] = link[link[v]];
          link[v] = to[link[v]][x];
        }
        diff[v] = len[v] - len[link[v]];
        if(diff[v] == diff[link[v]]) {
          slink[v] = slink[link[v]];
        }else{
          slink[v] = link[v];
        }
        last[n] = v;
      }else{
        last[n] = to[last[n]][x];
      }
      return;
    }
  }
}

string solve(string s){
  init();
  for(char c : s) add(c);
  string t = s;
  FORD(i,(int)s.size()-len[last[s.size()]]-1,0) t += s[i];
  return t;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  string s; cin>>s;
  auto t1 = solve(s);
  reverse(all(s));
  auto t2 = solve(s);
  reverse(all(t2));
  if(t1.size()<t2.size()) cout << t1 << endl; else cout << t2 << endl;
  return 0;
}