#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int p[n];
    int inv[n];
    for(int i = 0; i<n; i++){
        cin >> p[i];
        p[i]--;
        inv[p[i]] = i;
    }

    int last = -1;
    int ma = 0;
    int cur = 0;
    for(int i = 0; i<n; i++){
        if(inv[i] > last){
            last = inv[i];
            cur++;
            ma = max(ma, cur);
        }

        else{
            cur = 1;
            last = inv[i];
        }
    }

    cout << n - ma;
}