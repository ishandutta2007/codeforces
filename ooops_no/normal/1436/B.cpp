#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define int long long

bool prime(int v){
    for (int i = 2; i <= sqrt(v); i++){
        if (v % i == 0) return 0;
    }
    return 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if (n == 2){
            cout << "1 1" << endl;
            cout << "1 1" << endl;
        }
        else{
            int k = 1;
            while(1){
                if (prime(k * (n - 1) + 1) && !prime(k)){
                    break;
                }
                else{
                    k++;
                }
            }
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (i == j){
                        cout << 1 << " ";
                    }
                    else{
                        cout << k << " ";
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}