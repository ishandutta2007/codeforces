#include <bits/stdc++.h>
using namespace std;

// To execute C++, please define "int main()"
int main() {
  
  // Variables
  int n, m, a, b, temp;
  cin >> n >> m;
  vector<int> boy(n, 0);
  vector<int> girl(m, 0);
  
  // Read boys
  cin >> a;
  for (int i = 0; i < a; ++i) {
    cin >> temp;
    boy[temp] = 1;
  }
  
  // Read girls
  cin >> b;
  for (int i = 0; i < b; ++i) {
    cin >> temp;
    girl[temp] = 1;
  }
  
  // Process 
  // Simulate the process until day n * m
  for (int day = 0; day < 2000000; ++day) {
    int happy = boy[day % n] | girl[day % m];
    boy[day % n] = happy;
    girl[day % m] = happy;
  }
  
  // Check if all boys and girls are happy
  int count = 0; 
  for (int i = 0; i < n; ++i) { if (boy[i] == 1) ++count; }
  for (int i = 0; i < m; ++i) { if (girl[i] == 1) ++count; }
  
  // Print result
  if (count == n + m) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}

/* 
  Example 2: NO
         0 1 2 3
  Boys:  1 0
  Girls: 0 0 1 0
  
  day 0: 0 - 0
  Boys:  1 0
  Girls: 1 0 1 0
  
  day 1: 1 - 1
  Boys:  1 0
  Girls: 1 0 1 0
  
  day 2: 0 - 2
  Boys:  1 0
  Girls: 1 0 1 0
  
  day 3: 1 - 3
  Boys:  1 0
  Girls: 1 0 1 0
  
  day 4: 0 - 0
  Boys:  1 0
  Girls: 1 0 1 0
  
  Example 1: YES
  
  day 4: 0 - 1
  b: 1 1
  g: 1 1 1
  
  day 5: 1 - 2
  day 6: 0 - 0
  
  
  Example: n = 6, m = 4
  Period = LCM(n, m) = 12
  0: 0 0 
  1: 1 1
  2: 2 2 
  3: 3 3 
  4: 4 0
  5: 5 1
  6: 0 2
  7: 1 3
  8: 2 0
  9: 3 1
  10: 4 2 
  11: 5 3
  12: 0 0
  
  
  b: 0 0 0 
  g: 0 0 0 1
  
  
*/