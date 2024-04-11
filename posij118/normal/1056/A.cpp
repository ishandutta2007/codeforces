#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, y;
    cin >> n;

    int cnt[101];
    fill(cnt, cnt  + 101, 0);
    for(int i = 0; i<n; i++){
        cin >> x;
        for(int j = 0; j<x; j++){
            cin >> y;
            cnt[y]++;
        }
    }

    for(int i = 1; i<=100; i++){
        if(cnt[i] == n) cout << i << " ";
    }

}