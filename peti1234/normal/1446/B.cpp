#include <bits/stdc++.h>
using namespace std;

int szertek[5002][5002];
bool volt[5002][5002];
string a, b;
int n, m, maxval;

int LCS(int x, int y){
  if(!volt[x][y]){
    if(x == 0 || y == 0){
      return 0;
    }
    if(a[x-1] == b[y-1]){
      szertek[x][y] = LCS(x-1, y-1) + 2;
    }
      szertek[x][y] = max({LCS(x-1, y)-1, LCS(x, y-1)-1, szertek[x][y]});
      volt[x][y] = true;
      maxval=max(maxval, szertek[x][y]);
  }
    return szertek[x][y];
}

int main() {
  cin >> n >> m;
	cin >> a >> b;
  maxval = 0;
  LCS(n, m);
  cout << maxval;
	return 0;
}