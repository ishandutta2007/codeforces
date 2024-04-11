#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;

    int vals[(1 << n)];
    fill(vals, vals + (1 << n), -1);

    int inv[(1 << (n - 1))];

    if(x >= (1 << n)){
        cout << ((1 << n) - 1) << endl;

        for(int i = 0; i<(1 << n) - 1; i++){
            cout << (i ^ (i + 1)) << " ";
        }

        return 0;
    }


    else{
        int cnt = 0;
        for(int i = 0; i<(1 << n); i++){
            if(vals[i] == -1){
                vals[i] = cnt;
                vals[i ^ x] = cnt;
                inv[cnt] = i;
                cnt++;
            }
        }

        int cur = 0;
        cout << (1 << (n - 1)) - 1 << endl;
        for(int i = 0; i<(1 << (n - 1)) - 1; i++){
            cout << (cur ^ inv[i + 1]) << " ";
            cur = inv[i + 1];
        }
    }

}