#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, q, x, y, ans;
    cin >> n >> m >> q;

    string s, t;
    cin >> s >> t;

    if(n < m){
        for(int i=0; i<q; i++){
            cout << 0 << endl;
        }
        return 0;
    }

    int good[n-m+1];
    fill(good, good + n-m+1, 0);

    for(int i=0; i<n-m+1; i++){
        for(int j=0; j<m; j++){
            if(s[i+j] != t[j]) break;
            if(j== m-1) good[i] = 1;
        }
    }

    for(int i=0; i<q; i++){
        cin >> x >> y;
        ans = 0;
        for(int j = x-1; j<=y-m; j++){
            ans+=good[j];
        }

        cout << ans << endl;
    }

}