#include <bits/stdc++.h>

using namespace std;

const int  N = 200020;

int n;
int a[N];
int prefix[N];
int suffix[N];

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];

  prefix[2] = abs(a[2] - a[1]);
  suffix[n - 1] = abs(a[n - 1] - a[n]);

  for(int i = 3; i <= n; ++i) {
    prefix[i] = __gcd(prefix[i - 1], abs(a[i] - a[i - 1]));
  }

  for(int i = n - 2; i >= 1; --i) {
    suffix[i] = __gcd(suffix[i + 1], abs(a[i] - a[i + 1]));
  }

  int cntdiff = 0;
  map < int, int > cnt;

  for(int i = 1; i <= n; ++i) ++cnt[a[i]];

  set < int > myset; 

  for(int i = 1; i <= n; ++i) {
    //cntdiff += !(myset.count(a[i]));
    myset.insert(a[i]);
  }

  cntdiff = myset.size();

  for(int i = 1; i <= n; ++i) {
    if(cnt[a[i]] == 1) myset.erase(a[i]), cntdiff--;

    int c;
    if(i == 1) c = suffix[2];
    else if (i == n) c = prefix[n - 1];
    else c = __gcd(prefix[i - 1], suffix[i + 1]);

    if(c == 0) {
      if(cntdiff == 1) {
        cout << i << endl;
        return 0;
      }
    }
    else {
      if(cntdiff == n - 1 && *myset.begin() + c * (n - 2) == *myset.rbegin()) {
     //   cout << c << " " << *myset.begin() << " " << *myset.rbegin() << endl;
        cout << i << endl;
        return 0;
      }
    }

    if(cnt[a[i]] == 1) {
      myset.insert(a[i]);
      ++cntdiff;
    }
  }

  cout << -1;

  return 0;
}