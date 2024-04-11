#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        set<int> s;
        for(int i = 0; i<n; i++){
            int x;
            cin >> x;

            s.insert(x);
        }

        int flag = 0;

        for(int m = 1; m<=1000; m++){
            if(m * (k - 1) >= s.size() - 1){
                cout << m << endl;
                flag = 1;
                break;
            }
        }

        if(!flag) cout << -1 << endl;
    }

}