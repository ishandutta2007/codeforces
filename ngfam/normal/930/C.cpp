#include <bits/stdc++.h>

using namespace std;

template < class T > 
struct Fenwick{
  private :
    int N;
    vector < T > bit;

  public :
    Fenwick (int x){
      N = x + 10; 
      bit.resize(N, 0);
    }

    void upd(int i, T val){
      for(; i < N; i += i & -i){
        bit[i] += val;
      }
    }   

    T ask(int i){
      T ans = 0;
      for(; i > 0; i &= i - 1){
        ans += bit[i];
      }
      return ans;
    }
};



const int N = 100010;

int a[N];
int lds[N];
int lis[N];
int bit[N];
Fenwick < int > fwt(N);



void upd(int i, int val){
  i += 2;
  for(; i < N; i += i & -i) bit[i] = max(bit[i], val);
}

int get(int i, int start = 0){
  i += 2;
  int ans = start;
  for(; i > 0; i &= i - 1) ans = max(ans, bit[i]);
  return ans;
}

int main(){

  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    int u, v;
    scanf("%d%d", &u, &v); 
  
    fwt.upd(u, 1); fwt.upd(v + 1, -1);
  }

  for(int i = 1; i <= m; ++i){
    a[i] = fwt.ask(i);
  }


int ans = 0;

  for(int i = m; i >= 1; --i){
    lds[i] = get(a[i]) + 1;
    upd(a[i], lds[i]);
    ans = max(ans, lds[i]);
  }

  memset(bit, 0, sizeof bit);

  for(int i = 1; i <= m; ++i){
    lis[i] = get(a[i]) + 1;
    upd(a[i], lis[i]);
    ans = max(ans, lis[i]);
  }

  memset(bit, -1, sizeof bit);

  for(int i = m; i >= 1; --i){
    int g = get(a[i] - 1);
    if(g != -1){
      ans = max(ans, lis[i] + g);
    }

    upd(a[i], lds[i]);
  } 

  cout << ans;

	return 0;
}