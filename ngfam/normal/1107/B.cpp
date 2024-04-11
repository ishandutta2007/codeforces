#include <bits/stdc++.h>

using namespace std;

int sumdigit(int x) {
  if(x == 0) return 0;
  return x % 10 + sumdigit(x / 10);
}

int getdigit(int x) {
  if(sumdigit(x) < 10) return sumdigit(x);
  return getdigit(sumdigit(x));
}

long long dp[18][1010];

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL);

  int T;
  cin >> T;

  dp[0][0] = 1;
  for(int i = 0; i < 17; ++i) {
    for(int sum = 0; sum < 1010 - 100; ++sum) {
      for(int c = 0; c <= 9; ++c) {
        dp[i + 1][sum + c] += dp[i][sum];
      }
    }
  }

  while(T--) {
    long long k; int n;
    cin >> k >> n;

    vector < int > avail;

    for(int i = 0; i < 1010; ++i) if(getdigit(i) == n) avail.push_back(i);

    long long ans = 0, current = k, sum = 0;

    for(int i = 0; i < 18; ++i) {
      for(int c = 0; c < 10; ++c) {
        int fakesum = sum + c;
        long long fakecur = current;
        for(int x : avail) {
          if(fakesum <= x) {
            fakecur -= dp[18 - i - 1][x - fakesum];
          }
        }
        if(fakecur <= 0) {

          ans = ans * 10 + c;
          sum += c;
          break;
        }
        else {
          current = fakecur;
        }
      }
    }

    cout << ans << endl;
  }

  return 0;
}