#include <bits/stdc++.h>
#define ll long long

using namespace std;




int main() {
   // fstream cin("A.in");
   // ofstream cout("A.out");
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    int a = 1, b = n;
    int ans = 0;
    while(a < b) {
        a++;
        if(a < b) {
            b--;
            ans++;
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}