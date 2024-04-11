#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        bool flag = 0;
        int n, m, k;
        cin >> n >> m >> k;
        
        int h[n];
        cin >> h[0];
        for(int i = 0; i <n-1; i++){
            cin >> h[i+1];
            m += min(h[i] - h[i + 1] + k, h[i]);
            if(m < 0 && !flag){
                cout << "NO" << endl;
                flag = 1;
            }
        }
        
        if(!flag) cout << "YES" << endl;
    }
    return 0;
}