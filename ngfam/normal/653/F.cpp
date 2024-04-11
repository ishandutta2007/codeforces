#include <bits/stdc++.h>

using namespace std;

const long long N = 5e5 + 1, mod = 1e9 + 7, base = 17;

int n, m, d, c, up;
int f[N];
int sum[N];
int it[N * 4];
int common[N];
int small[N * 2];
int tmp[N];
int flag[N * 2][30];
unsigned long long hashes[N];
long long pw[N];
string srr;
vector < int > idx[N * 2];

int convert(char c){
  if(c == '('){
    return 7;
  }
  return 13;
}

long long ask(int l, int r){
  long long sub = 0;
  if(l > 0){
    sub = hashes[l - 1];
  }
  return (hashes[r] - sub * pw[r - l + 1]);
}

int lcp(int x, int y){
  int low = 0, high = srr.size() - min(x, y) - 1, ans = -1;
  while(low <= high){
    int val = (low + high) >> 1;
    if(ask(x, x + val) == ask(y, y + val)){
      ans = val;
      low = val + 1;
    }
    else{
      high = val - 1;
    }
  }
  return ans;
}

bool cmp(int u, int v){
  if(small[u] != small[v]){
    return small[u] < small[v];
  }
  return small[u + up] < small[v + up];
}

void build(int i, int l, int r){
  if(l == r){
    it[i] = sum[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(i * 2, l, mid);
  build(i * 2 + 1, mid + 1, r);
  it[i] = min(it[i * 2], it[i * 2 + 1]);
}

int query(int i, int l, int r){
  if(d > r || l > c){
    return N;
  }
  if(l >= d && r <= c){
    return it[i];
  }
  int mid = (l + r) >> 1;
  return min(query(i * 2, l, mid), query(i * 2 + 1, mid + 1, r));
}

int range(int l, int r){
  int lgr = log2(r - l + 1);
  return min(flag[l][lgr], flag[r - (1 << lgr) + 1][lgr]);
}

bool correct(int l, int r){
  int sub = 0;
  if(l > 0){
    sub = sum[l - 1];
  }
  return (sum[r] == sub && range(l, r) >= sub);
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
    //freopen(".out", "w", stdout);
  #endif // pts
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> n >> srr;
  for(int i = 0; i < srr.size(); ++i){
    f[i] = i;
    small[i] = srr[i];
  }
  hashes[0] = convert(srr[0]);
  for(int i = 1; i < srr.size(); ++i){
    hashes[i] = (1LL * hashes[i - 1] * base + convert(srr[i]));
  }
  pw[0] = 1;
  for(int i = 1; i <= srr.size(); ++i){
    pw[i] = (pw[i - 1] * base);
  }
  for(up = 1; up <= srr.size(); up *= 2){
    sort(f, f + n, cmp);
    tmp[f[0]] = 0;
    for(int i = 1; i < srr.size(); ++i){
      tmp[f[i]] = tmp[f[i - 1]] + cmp(f[i - 1], f[i]);
    }
    for(int i = 0; i < srr.size(); ++i){
      small[i] = tmp[i];
    }
    if(small[f[n - 1]] == n - 1){
      break;
    }
  }
  #ifdef pts
    cerr << "suffix arrray : " << endl;
    for(int i = 0; i < srr.size(); ++i){
      cerr << f[i] << endl;
    }
  #endif // pts
  for(int i = 1; i < srr.size(); ++i){
    common[i] = lcp(f[i - 1], f[i]) + 1;
  }
  sum[0] = (srr[0] == '(' ? 1 : -1);
  for(int i = 1; i < srr.size(); ++i){
    sum[i] = sum[i - 1] + (srr[i] == '(' ? 1 : -1);
  }
  for(int i = 0; i < srr.size(); ++i){
    for(int j = 0; j < 30; ++j){
      flag[i][j] = N * 2;
    }
  }
  for(int i = 0; i < srr.size(); ++i){
    flag[i][0] = sum[i];
  }
  for(int j = 1; j <= 20; ++j){
    for(int i = 0; i < srr.size(); ++i){
      flag[i][j] = min(flag[i][j - 1], flag[i + (1 << (j - 1))][j - 1]);
    }
  }
  for(int i = 0; i < srr.size(); ++i){
    idx[sum[i] + N].push_back(i);
  }
  long long answer = 0;
  for(int i = 0; i < srr.size(); ++i){
    int least = common[i] + 1, u = f[i];
    int values = 0;
    if(u > 0){
      values = sum[u - 1];
    }
    int curr = values + N;
    int low = lower_bound(idx[curr].begin(), idx[curr].end(), u + least - 1) - idx[curr].begin();
    if(low == idx[curr].size()){
      continue;
    }
    int high = idx[curr].size() - 1, ans = low - 1, old = low;
    while(low <= high){
      int mid = (low + high) >> 1;
      int tt = idx[curr][mid];
      if(range(u, tt) >= values){
        low = mid + 1;
        ans = mid;
      }
      else{
        high = mid - 1;
      }
    }
    answer += (ans - old + 1);
  }
  cout << answer;
  return 0;
}