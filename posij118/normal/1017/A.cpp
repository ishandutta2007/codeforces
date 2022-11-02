#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;

int main(){
    int n;
    cin >> n;

    int a[n][4];
    pair<int, int> s[n];
    for(int i=0; i<n; i++){
        s[i] = make_pair(0, -i);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<4; j++){
            cin >> a[i][j];
            s[i].first+=a[i][j];
        }

    }

    sort(s, s + n);
    reverse(s, s + n);
    for(int i=0; i<n; i++){
        if(s[i].second == 0) cout << i+1;
    }

}