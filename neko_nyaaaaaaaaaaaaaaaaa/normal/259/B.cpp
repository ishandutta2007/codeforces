#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int a[3][3];
	for (int i = 0; i < 3; i++) {
	      for (int j = 0; j < 3; j++) {
	            cin >> a[i][j];
	      }
	}
	
	for (a[0][0] = 1; a[0][0] <= 100000; a[0][0]++) {
	      a[1][1] = a[0][0] + a[0][1] + a[0][2] - a[1][0] - a[1][2];
	      a[2][2] = a[0][0] + a[0][1] + a[0][2] - a[2][0] - a[2][1];
	      
	      if (a[1][1] <= 100000 && a[1][1] && a[2][2] && a[2][2] <= 100000 && a[0][0] + a[2][2] == a[2][0] + a[0][2]) {
	            for (int i = 0; i < 3; i++) {
	                  for (int j = 0; j < 3; j++) {
	                        cout << a[i][j] << " ";
	                  }
	                  cout << endl;
	            }
	            return 0;
	      }
	} 
	
	return 0;
}