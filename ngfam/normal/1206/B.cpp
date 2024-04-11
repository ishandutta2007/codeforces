#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n;
  vector < int > a(n);

  int prod = 1;
  int count_zero = 0;
  long long sum_neg = 0, sum_pos = 0;

  for(int &x : a) {
    cin >> x;
    if(x == 0) {
      count_zero++;
    }
    else {
      if(x > 0) sum_pos += x - 1;
      else sum_neg += abs(x) - 1, prod *= -1;
    }
  }


  if(count_zero > 0) cout << sum_pos + sum_neg + count_zero << endl;
  else {
    cout << sum_pos + sum_neg + 2 * (prod == -1) << endl;
  }
  return 0;
}