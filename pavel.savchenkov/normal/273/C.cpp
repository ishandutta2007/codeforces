#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>
#include <cmath>

using namespace std;

#define pb push_back
#define f first
#define s second
#define LL long long
#define uLL unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define sz(A) ((int)(A).size())
#define y1 qwertyuiopasdfghjklzxcvbnm
#define y0 ehfoiuvhefroerferjhfjkehfjke

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MAXN = 3 * (int) 1e5 + 10;

vector <int> g[MAXN];
int c[MAXN];
bool inq[MAXN];
queue <int> q;
int n, m;

bool norm(int v) {
  int bd = 0;
  for (int i = 0; i < sz(g[v]); i++)
    if  (c[g[v][i]] == c[v]) bd++;
  
  return bd <= 1;
}

void push(int v) {
  if  (!inq[v])
    q.push(v);
  inq[v] = true;
}

int pop() {
  int v = q.front();
  q.pop();
  inq[v] = false;
  
  return v;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b; scanf("%d %d", &a, &b);
    a--; b--;
    g[a].pb(b); g[b].pb(a);
  }
  
  memset(c, 0, sizeof c);
  
  for (int i = 0; i < n; i++)
    if  (!norm(i)) push(i);
    
  while (!q.empty()) {
    int v = pop();
        
    if  (!norm(v)) {
      c[v] = 1 - c[v];
      for (int i = 0; i < sz(g[v]); i++)
        if  (!norm(g[v][i])) push(g[v][i]); 
    }
  }
  
  for (int i = 0; i < n; i++)
    printf("%d", c[i]);
  return 0;
}