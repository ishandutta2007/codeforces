#include <bits/stdc++.h>

using namespace std;

const int N = 400020;

int n;
int a[N];
int b[N];
vector < int > lds[N / 2];

struct SegmentTreeMax{
  int it[N << 2];
  int lazy[N << 3];

  #define mid ((l + r) >> 1)

  void Init(){
    memset(it, 0, sizeof it);
    memset(lazy, 0, sizeof lazy);
  }

  void push(int x){
    it[x] += lazy[x];
    lazy[x + x] += lazy[x];
    lazy[x + x + 1] += lazy[x];
    lazy[x] = 0;
  }

  void update(int x, int l, int r, int u, int v, int val){
    if(v < u) return;
    push(x);
    if(l > v || r < u) return;
    if(l >= u && r <= v){
      lazy[x] += val;
      push(x);
      return;
    }
    update(x + x, l, mid, u, v, val);
    update(x + x + 1, mid + 1, r, u, v, val);
    it[x] = max(it[x + x], it[x + x + 1]);  
  }

  void modify(int x, int l, int r, int pos, int val){
    push(x);
    if(l > pos || r < pos) return;
    it[x] = max(it[x], val);
    if(l == r) return;
    modify(x + x, l, mid, pos, val);
    modify(x + x + 1, mid + 1, r, pos, val);
    it[x] = max(it[x + x], it[x + x + 1]);
  }

  int query(int x, int l, int r, int u, int v){
    push(x);
    if(u > v) return 0;
    if(l > v || r < u) return 0;
    if(l >= u && r <= v) return it[x];
    int ret = max(query(x + x, l, mid, u, v), query(x + x + 1, mid + 1, r, u, v));
    it[x] = max(it[x + x], it[x + x + 1]);
    return ret;
  }

  #undef mid
}T, LIS;

vector < int > nums;
int pos[N];

int get(int x){
  if(x < -N) return 0;
  return lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
}

int main(){



  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
    nums.push_back(a[i] - i);
    nums.push_back(a[i] - i + 1);
  }



  sort(nums.begin(), nums.end());
  nums.erase(unique(nums.begin(), nums.end()), nums.end());


  int m = 0;

  lds[0].push_back(1e9 + 10);

  for(int i = n; i >= 1; --i){
    int val = a[i] - (i - 1);


    int low = 0, high = m, ans = 0;

    while(low <= high){
      int mid = (low + high) >> 1;
      if(lds[mid].back() >= val){
        ans = mid;
        low = mid + 1;
      }
      else{
        high = mid - 1;
      }
    }

    if(ans == m) ++m;
    lds[pos[i] = ans + 1].push_back(val);
  }

  int ans = n - m;

  int sz = nums.size();

  for(int i = m; i >= 1; --i){
    LIS.update(1, 1, sz, 1, get(lds[i].back()), 1);
 //   debug(lds[i]);
  }




  vector < int > f;

  for(int i = 1; i <= n; ++i){
    int p = pos[i], val = a[i] - i + 1, low = -1e9;
    lds[p].pop_back();
    if(lds[p].size()) low = lds[p].back();

    if(lds[m].empty()) m--;

    LIS.update(1, 1, sz, get(low) + 1, get(val), -1);
    T.update(1, 1, sz, get(low) + 1, get(val), -1);




    if(i == 1){
      ans = min(ans, n - 1 - m);
    }
    else{
        int ins = upper_bound(f.begin(), f.end(), a[i - 1] - i + 1) - f.begin();
        if(ins == f.size()) f.push_back(a[i - 1] - i + 1);
        else f[ins] = a[i - 1] - i + 1; 
        ins = ins + 1;
       int ret;
      T.modify(1, 1, sz, get(a[i - 1] - i + 1), ret = ins + LIS.query(1, 1, sz, get(a[i - 1] - i + 1), get(a[i - 1] - i + 1)));
      ans = min(ans, n - 1 - ret);
    }
  }

  cout << ans;

	return 0;
}