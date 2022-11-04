#include <bits/stdc++.h>


using namespace std;



int main() {
  //  fstream cin("B.in");
  //  ofstream cout("B.out");
    int h1, h2, a, b;
    ios::sync_with_stdio(false);
    cin >> h1 >> h2 >> a >> b;
    if(a <= b && a * 8 + h1 < h2) {
        cout << -1;
        return 0;
    }
    int cnt = 0;
    h1 += a * 8;
    while(h1 < h2) {
        h1 -= b * 12;
        h1 += a * 12;
        cnt++;
    }
    cout << cnt;
  //  cin.close();
  //  cout.close();
    return 0;
}