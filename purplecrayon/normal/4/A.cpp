#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    cout << (n > 2 && (n&1^1) ? "YES\n" : "NO\n");
}