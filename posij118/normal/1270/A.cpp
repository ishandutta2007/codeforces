#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k1, k2;
        cin >> n >> k1 >> k2;

        for(int i = 0; i<n; i++){
            int x;
            cin >> x;

            if(x == n){
                if(i < k1) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }
    }

}