#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, a, b;
        cin >> n >> x >> a >> b;
        cout << min(n - 1, abs(b - a) + x) << endl;
    }
}