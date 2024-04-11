#include <bits/stdc++.h>

using namespace std;

const int N = 300300;

int sz;
int cnt[N * 30];
int trie[N * 30][2];

void add(int x){
  int node = 0;
  for(int i = 29; i >= 0; --i){
    int bit = (x >> i) & 1;
    if(trie[node][bit] == 0) trie[node][bit] = ++sz;
    node = trie[node][bit];
    ++cnt[node];
  }
}

int find(int key){
  int node = 0, ans = 0;
  for(int i = 29; i >= 0; --i){
    int bit = (key >> i) & 1;

    if(bit){
      if(cnt[trie[node][1]]) {
        node = trie[node][1];
      }
      else{
        ans += (1 << i);
        node = trie[node][0];
      }
    }
    else{
      if(cnt[trie[node][0]]){
        node = trie[node][0];
      }
      else{
        ans += (1 << i);
        node = trie[node][1];
      }
    }
    --cnt[node];
  }
  return ans;
}

int n;
int a[N];
int b[N];

int main(){

  cin >> n;
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", b + i);
    add(b[i]);
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", find(a[i]));
  }

	return 0;
}