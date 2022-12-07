#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

char s[N];
int n, pos;
int f[N], diff[N];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		//freopen("1.out", "w", stdout);
	#endif
  scanf("%d%d", &n, &pos);
  scanf("%s", s + 1);
  int ans = 0;
  for(int i = 1; i <= n / 2; ++i){
    if(s[i] != s[n - i + 1]){
      diff[i] = 1;
      char cmax = max(s[i], s[n - i + 1]), cmin = min(s[i], s[n - i + 1]);
      f[i] = min(cmin - 'a' + 'z' - cmax + 1, cmax - cmin);
      ans += f[i];
    }
  }
  int val = n;

  int low = n, high = 1, nearlow = n + 1, nearhigh = 0, cnt = 0;
  for(int i = 1; i <= n; ++i){
    if(diff[i] == 1){
      ++cnt;
      low = min(low, i);
      high = max(high, i);
      if(i > pos){
        nearlow = min(nearlow, i);
      }
      if(i < pos){
        nearhigh = max(nearhigh, i);
      }
    }
  }

  if(cnt == 0){
    cout << 0;
    return 0;
  }


  if(cnt == 1){
    int maxpos = max(pos, low), minpos = min(pos, low);
    val = min(val, min(minpos + n - maxpos, maxpos - minpos));
  }
  else{
    if(nearhigh > 0){
      if(nearlow <= n) val = min(val, pos + n - nearlow);
      else val = min(val, pos - low);
      //cout << low << " " << high << endl;
      val = min(val, pos - low + high - low);
    }
    if(nearlow <= n){
      if(nearhigh > 0) val = min(val, n - pos + nearhigh);
      else val = min(val, high - pos);
      val = min(val, high - pos + high - low);
    }
  }

  for(int i = 1; i <= n / 2; ++i){
    if(diff[i] == 1) diff[n - i + 1] = 1, diff[i] = 0;
  }
  low = n, high = 1, nearlow = n + 1, nearhigh = 0, cnt = 0;
  for(int i = 1; i <= n; ++i){
    if(diff[i] == 1){
      ++cnt;
      low = min(low, i);
      high = max(high, i);
      if(i > pos){
        nearlow = min(nearlow, i);
      }
      if(i < pos){
        nearhigh = max(nearhigh, i);
      }
    }
  }

  if(cnt == 1){
    int maxpos = max(pos, low), minpos = min(pos, low);
    val = min(val, min(minpos + n - maxpos, maxpos - minpos));
  }
  else{
    //cerr << low << " " << high << endl;
    if(nearhigh > 0){
      if(nearlow <= n) val = min(val, pos + n - nearlow);
      else val = min(val, pos - low);
      //cout << low << " " << high << endl;
      val = min(val, pos - low + high - low);
    }
    if(nearlow <= n){
      if(nearhigh > 0) val = min(val, n - pos + nearhigh);
      else val = min(val, high - pos);
      val = min(val, high - pos + high - low);
    }
  }
  cout << ans + val;
	return 0;
}