#include <bits/stdc++.h>

using namespace std;

const int N = 200020;

int n, q;
int a[N];
int cnt[N];
int last[N];
int first[N];


int lab[N];
vector < int > w[N];

int find(int x) {
  return (lab[x] < 0 ? x : lab[x] = find(lab[x]));
}

void join(int x, int y) {
  x = find(x); y = find(y);
  if(x == y) return;
  if(lab[x] > lab[y]) swap(x, y);
  lab[x] += lab[y];
  lab[y] = x;
}

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 


  cin >> n >> q;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++cnt[a[i]];
    last[a[i]] = i;
    if(first[a[i]] == 0) first[a[i]] = i;
  }

  memset(lab, -1, sizeof lab);

  set < int > elements; ///

  for(int i = 1; i <= n; ++i) {
    if(!elements.empty()) {
      join(a[i], *elements.begin());
    }
    if(i == first[a[i]]) elements.insert(a[i]);
    if(i == last[a[i]]) elements.erase(a[i]);
  }

  for(int i = 0; i < N; ++i) {
    if(cnt[i]) w[find(i)].push_back(cnt[i]);
  }


  long long ans = 0;

  for(int i = 0; i < N; ++i) {
    sort(w[i].begin(), w[i].end());
    for(int j = 0; j + 1 < w[i].size(); ++j) ans += w[i][j];
  }

  cout << ans;

  return 0;
}