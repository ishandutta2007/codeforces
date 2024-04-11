#include <iostream>
using namespace std;
 
int main() {
 
      int n;
      cin >> n;
      int a[n], b[n];
      int max = 1, min = 1000000000;
      for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
            min = (a[i] < min ? a[i] : min);
            max = (b[i] > max ? b[i] : max);
      }
      for (int i = 0; i < n; i++) {
            if (a[i] == min && b[i] == max) {cout << i+1; return 0;}
      }
       cout << -1;
 
 
	return 0;
}