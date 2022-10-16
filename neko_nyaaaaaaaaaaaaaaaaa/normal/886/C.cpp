#include <bits/stdc++.h>
using namespace std;

/*
min  x 0 1 0 1 3

room 1 1 1 2 3 2
      t1 2 3 4 5

index0 1 2 3 4 5
room 1 2 3 1 2 
t    x 0 1 0 1 3

index 0 1 2 3 4
t     0 0 1 1 1
room  1 1 1 2 3
*/

int main() {
	
  // Input
  int n;
  cin >> n;
  vector<int> t(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }

  // Solve
  // Initially at room 1, t0 = 0
  // enter in exactly same minute
  // -> sort
  // -> t[i] == t[i - 1] implies rooms connected
  sort(t.begin(), t.end());
  int count = 0;
  for (int i = 1; i < n; ++i) {
    if (t[i] == t[i - 1]) {
      count++;
    }
  }
  cout << count+1 << endl;

  /*
  t[i] ... 4 4 4  4 ... 
  i    ... 5 7 8 11 ...  
  -> 3 rooms
  
  */

	return 0;
}