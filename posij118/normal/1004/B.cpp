#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        if(i % 2 == 0) cout << 1;
        else cout << 0;
    }
}