#include <bits/stdc++.h>


using namespace std;



int main() {
  //  fstream cin("B.in");
  //  ofstream cout("B.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int nr1 = 1, nr2 = 2 * n + 1, nr3 = 2 * n + 2, nr4 = 2;
    for(i = 1; i <= 4 * n; i += 4) {
        if(nr2 <= m)
           cout << nr2 << " ";
        nr2 += 2;
        if(nr1 <= m) {
            cout << nr1 << " ";
            nr1 += 2;
        }
        if(nr3 <= m) {
            cout << nr3 << " ";
            nr3 += 2;
        }
        if(nr4 <= m) {
            cout << nr4 << " ";
            nr4 += 2;
        }
    }

  //  cin.close();
  //  cout.close();
    return 0;
}