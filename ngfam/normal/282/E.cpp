#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, sz;
long long a[N];
int cnt[N * 90];
long long suf[N];
long long pre[N];
int trie[N * 45][2];

void ins(long long x, int add){
  int curr = 0;
  for(int i = 43; i >= 0; --i){
    int c = (x >> i) & 1;
    if(trie[curr][c] == 0){
      trie[curr][c] = ++sz;
    }
    curr = trie[curr][c];
    cnt[curr] += add;
  }
}

long long query(long long x){
  int curr = 0;
  long long answer = 0;
  for(int i = 43; i >= 0; --i){
    int c = (x >> i) & 1;
    if(trie[curr][1 - c] != 0 && cnt[trie[curr][1 - c]] > 0){
      curr = trie[curr][1 - c];
      answer |= (1LL << i);
      continue;
    }
    curr = trie[curr][c];
  }
  return answer;
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  long long answer = 0;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%lld", a + i);
  }
  for(int i = 1; i <= n; ++i){
    pre[i] = pre[i - 1] ^ a[i];
    answer = max(answer, pre[i]);
  }
  for(int i = n; i >= 1; --i){
    suf[i] = suf[i + 1] ^ a[i];
    answer = max(answer, suf[i]);
  }
  for(int i = 1; i <= n; ++i){
    ins(pre[i], 1);
  }
  for(int i = n; i > 1; --i){
    ins(pre[i], -1);
    answer = max(answer, query(suf[i]));
  }
  cout << answer;
  return 0;
}