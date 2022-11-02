#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, x;
        cin >> n >> x;

        int ma = 0;
        bool flag = 0;
        for(int i = 0;i<n; i++){
            int y;
            cin >> y;
            if(x == y) flag = 1;
            ma = max(ma, y);
        }

        if(flag) cout << 1 << endl;
        else if(ma > x) cout << 2 << endl;
        else cout << (x - 1) / ma + 1 << endl;
    }

}