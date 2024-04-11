#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int a, b, n;
        cin >> a >> b >> n;

        int ans = 0;
        while(max(a, b) <= n){
            if(a < b) a = a + b;
            else b = a + b;
            ans++;
        }

        cout << ans << endl;
    }

}