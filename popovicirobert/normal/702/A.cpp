#include <bits/stdc++.h>


using namespace std;


int v[100001];

int main() {
   // fstream cin("A.in");
   // ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    int ans = 0;
    int cnt = 0;
    for(i = 1; i <= n; i++) {
        if(v[i] > v[i - 1])
            cnt++;
        else {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    cout << max(ans, cnt);
  //  cin.close();
  //  cout.close();
    return 0;
}