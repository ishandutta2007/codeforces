#include <bits/stdc++.h>

using namespace std;

const int N = 100100;
const int BlockSize = 320;

int n, q;
char a[N];
int idx[N];
int mostleft[N];
int cnt[N][11][11][5];

int Nadeko(char x){
  if(x == 'A'){
    return 1;
  }
  if(x == 'T'){
    return 2;
  }
  if(x == 'G'){
    return 3;
  }
  return 4;
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%s", a + 1);
  n = strlen(a + 1);
  for(int i = 1; i <= n; ++i){
    idx[i] = (i - 1) / BlockSize + 1;
    if(mostleft[idx[i]] == 0){
      mostleft[idx[i]] = i;
    }
    for(int x = 1; x <= 10; ++x){
      ++cnt[idx[i]][x][(i - mostleft[idx[i]]) % x][Nadeko(a[i])];
    }
  }
  scanf("%d", &q);
  while(q--){
    int t, l, r;
    char read[11];
    scanf("%d", &t);
    if(t == 1){
      scanf("%d%s", &l, &read);
      for(int x = 1; x <= 10; ++x){
        --cnt[idx[l]][x][(l - mostleft[idx[l]]) % x][Nadeko(a[l])];
        ++cnt[idx[l]][x][(l - mostleft[idx[l]]) % x][Nadeko(read[0])];
      }
      a[l] = read[0];
      continue;
    }
    scanf("%d%d%s", &l, &r, read);
    int m = strlen(read), ans = 0, pos;
    for(int x = l; idx[x] == idx[l] && x <= r; ++x){
      ans += (a[x] == read[(x - l) % m]);
      pos = x + 1;
    }
    if(idx[r] != idx[l]){
      for(int x = r; idx[x] == idx[r]; --x){
        ans += (a[x] == read[(x - l) % m]);
      }
    }
    //cout << pos << endl;
    int base = (pos - l) % m;
    for(int x = idx[l] + 1; x < idx[r]; ++x){
      for(int t = 0; t < m; ++t){
        ans += cnt[x][m][(t - base + m) % m][Nadeko(read[t])];
      }
      base += BlockSize;
      base %= m;
    }
    printf("%d\n", ans);
  }
  return 0;
}