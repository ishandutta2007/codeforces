#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  int n, I; 
  cin >> n >> I;

  vector < int > a(n);
  for(int &x : a) cin >> x;

  sort(a.begin(), a.end());

  vector < int > b = a;
  b.erase(unique(b.begin(), b.end()), b.end());

  I *= 8;
  int ans = n;

  int len = 1;
  while(len + 1 <= b.size() && n * ceil(log2(len + 1)) <= I) ++len;

  int pterleft = 0, pterright = n - 1;

  int cur = 0;


  for(int i = 0; i < b.size(); ++i) {
    int j = i + len - 1;
    if(j >= b.size()) break;
    while(a[pterleft] < b[i]) {
      ++cur;
      ++pterleft;
    } 
    while(a[pterright] > b[j]) {
      ++cur;
      --pterright;
    }
    while(pterright < n - 1 && a[pterright + 1] <= b[j]) {
      --cur;
      ++pterright;
    }


    //cout << b[i] << " " << b[j] << " " << pterleft << " " << pterright << " " << cur << endl;
    ans = min(ans, cur);
  }

  cout << ans;


  return 0;
}