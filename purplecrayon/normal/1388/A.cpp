#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> q;

    while(q--){
        int n; cin >> n;
        if(n <= 30){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            if(n == 36 || n == 40 || n == 44){
                cout << 6 << ' ' << 10 << ' ' << 15 << ' ' << n - 31 << endl;
            }
            else{
                cout << 6 << ' ' << 10 << ' ' << 14 << ' ' << n - 30 << endl;
            }
        }
    }
}