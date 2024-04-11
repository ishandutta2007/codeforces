#include <bits/stdc++.h>
using namespace std;
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t, n, a[100001];
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a, a + n);
        if(n & 1)
            cout << a[n / 2] << " ";
        for(int i = 0, j = 1; i < n / 2; ++i, j++){
            cout << a[n / 2 - j] << " " << a[n / 2 + i + (n & 1)]  << " ";
        }
        cout << '\n';
    }
 
    return 0;
}