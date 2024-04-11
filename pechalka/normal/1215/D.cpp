#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <set>

using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int sum = 0;
  int cnt1 = 0;
  int cnt2 = 0;
  for (int i = 0; i < n / 2; ++i){
    if (s[i] != '?')
      sum += (s[i] - '0');
    else
      ++cnt1;
  }
  for (int i = n / 2; i < n; ++i){
    if (s[i] != '?')
      sum -= (s[i] - '0');
    else
      ++cnt2;
  }
  if (sum == (cnt2 - cnt1) / 2 * 9)
    cout << "Bicarp";
  else
    cout << "Monocarp";
  return 0;
}