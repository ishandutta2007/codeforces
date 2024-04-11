#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
  int t;
  cin >> t;
  for (int step = 0; step < t; ++step){
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
      cin >> A[i];
    sort(A.begin(), A.end());
    if (A[n - 2] == 1)
      cout << "0\n";
    else
      cout << min(A[n - 2] - 1, n - 2) << "\n";
  }
  return 0;
}