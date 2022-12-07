#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, firstWater, lastGrass;
pair < long long, int > a[N];

int main(){
  
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i].first;
  }
  
  string read;
  cin >> read;
  
  firstWater = n + 1; lastGrass = 0;
  
  for(int i = 0; i < n; ++i) {
    if(read[i] == 'G') a[i + 1].second = 1, lastGrass = i + 1;
    else if (read[i] == 'W') a[i + 1].second = 2, firstWater = min(firstWater, i + 1);
    else a[i + 1].second = 3;
  }
  
  if(a[1].second == 3) {
    cout << -1;
    return 0;
  }
  
  set < int > lava;
  long long ans = 0;
  
  for(int i = n; i >= 1; --i) {
    if(a[i].second == 2) {
      while(a[i].first > 0 && lava.size() > 0) {
        int p = *lava.begin();
        if(a[p].first == 0) {
          lava.erase(p);
          continue;
        }
        
        if(a[p].first < a[i].first) { 
          a[i].first -= a[p].first;
          ans += a[p].first * 4;
          a[p].first = 0;
          lava.erase(p);
          continue;
        }
                
        ans += a[i].first * 4;
        a[p].first -= a[i].first;
        a[i].first = 0;
      }
    }
    else if(a[i].second == 3) {
      lava.insert(i); 
    }
  }
  
    
  set < int > grass;
  
  for(int i = n; i >= 1; --i) {
    if(a[i].second == 2) {
      while(a[i].first > 0 && grass.size() > 0) {
        int p = *grass.rbegin();
        if(a[p].first == 0) {
          grass.erase(p);
          continue;
        }
        
        if(a[p].first < a[i].first) { 
          a[i].first -= a[p].first;
          ans += a[p].first * 4;
          a[p].first = 0;
          grass.erase(p);
          continue;
        }
        
        ans += a[i].first * 4;
        a[p].first -= a[i].first;
        a[i].first = 0;
      }
    }
    else {
      if(a[i].second == 1) {
        grass.insert(i);
      }
    }
  }
  
  
  int pos = n;
  
  for(int i = 1; i <= n; ++i) if(a[i].second == 2 && a[i].first) {
    pos = i - 1;
    break;
  }
  
  lava.clear();
  
  for(int i = n; i >= 1; --i) {
    if(a[i].second == 1) {
      while(a[i].first > 0 && lava.size() > 0) {
        int p = *lava.begin();
        if(a[p].first == 0) {
          lava.erase(p);
          continue;
        }
        
        if(a[p].first < a[i].first) { 
          a[i].first -= a[p].first;
          ans += a[p].first * 6;
          a[p].first = 0;
          lava.erase(p);
          continue;
        }
        
        ans += a[i].first * 6;
        a[p].first -= a[i].first;
        a[i].first = 0;
      }
    }
    else if(a[i].second == 3) lava.insert(i);
  }
  
  for(int x : lava) if(a[x].first) {
    if(x > firstWater) ans += 4 * a[x].first;
    else ans += 6 * a[x].first;
    a[x].first = 0;
  } 
  
  
  long long totGrass = 0, totWater = 0;

  for(int i = 1; i <= n; ++i) {
    if(a[i].second == 1) totGrass += a[i].first;
    else if(a[i].second == 2) totWater += a[i].first;
  }
    
  
  ans += (totGrass / 2) * 6 + (totGrass % 2) * 3;
  ans += (totWater / 2) * 4 + (totWater % 2) * 2;
  
  cout << ans;
  
  return 0;
}