#include <bits/stdc++.h>

using namespace std;

const int N = 500050;

int n;
int a[N];
int b[N];
long long H[N];

int check(int d) {
  int m = n;
  for(int i = 1; i <= n; ++i) b[i] = a[i];
  b[++m] = d;
  
  sort(b + 1, b + m + 1);
  reverse(b + 1, b + m + 1);
  for(int i = 1; i <= m; ++i) H[i] = H[i - 1] + b[i];
  
  
  
  int w = m;
  
  for(int i = 1; i <= m; ++i) {
    while(w > 0 && b[w] < i) w = w - 1;
    int y = max(i, w);
    
    if(H[i] > 1LL * i * (y - 1) + H[m] - H[y]) {
      if(d >= i) return 1;
      else return 2;
    }
  }
  return 0;
}

int main(){
  
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
  long long tot = 0;
  
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    tot += a[i];
  }
  
  int mod = tot % 2;
  
  vector < int > vec;
  
  for(int i = mod; i <= n; i += 2){
    vec.push_back(i);
  }
    
  
  int l = 0, r = vec.size() - 1, ans = -1;
  
  while(l <= r) {
    int mid = (l + r) >> 1;
    int k = check(vec[mid]);
    
    if(k == 0) {
      ans = mid;
      break;
    }
    else {
      if(k == 1) r = mid - 1;
      else l = mid + 1;
    }
  }
  
  if(ans == -1) {
    cout << -1;
    return 0;
  }
  
  l = 0, r = ans; 
  int lowans = ans;
  
  while(l <= r) {
    int mid = (l + r) >> 1;
    int k = check(vec[mid]);
    
    if(k == 0) {
      lowans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  
  l = ans; r = vec.size() - 1; 
  int upans = ans;
  
  while(l <= r) {
    int mid = (l + r) >> 1;
    int k = check(vec[mid]);
    
    if(k == 0) {
      upans = mid;
      l = mid + 1;
    }
    else{
      r = mid - 1;
    }
  }
  
  for(int i = lowans; i <= upans; ++i) {
    cout << vec[i] << " ";
  }
  
  return 0;
}