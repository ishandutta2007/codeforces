#include <bits/stdc++.h>


using namespace std;

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, a, b, ans;
    ios::sync_with_stdio(false);
    cin >> a >> b;
    ans = 1;
    for(i = 1; i <= min(a, b); i++)
      ans *= i;
    cout << ans;
    //cin.close();
   // cout.close();
    return 0;
}