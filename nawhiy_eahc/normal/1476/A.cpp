#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(k < n){
            k = (n + k - 1)/k * k;
        }
        if(k%n == 0) cout << k/n << "\n";
        else cout << k/n + 1 << "\n";
    }
}