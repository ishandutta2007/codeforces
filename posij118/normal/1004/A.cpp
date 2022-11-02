#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int n, d, a, mi;
    cin >> n >> d;

    int x[n];
    for(int i=0; i<n; i++){
        cin >> x[i];
    }

    set<int> ans;

    for(int i=0; i<n; i++){
        a = x[i] - d;
        mi = d;

        for(int j=0; j<n; j++){
            if(abs(a - x[j]) < d) break;
            if(j == n-1) ans.insert(a);
        }

        a = x[i] + d;
        mi = d;

        for(int j=0; j<n; j++){
            if(abs(a - x[j]) < d) break;
            if(j == n-1) ans.insert(a);
        }
    }

    cout << ans.size();


}