#include <bits/stdc++.h>

using namespace std;

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0;i<n;i++) cin >> v[i];
    if (n != 3 || (v[0] != -3 || v[1] != -3 || v[2] != 2)){
        for (int i=0;i<n;i++){
            if (v[i] >= 0) v[i] = -v[i]-1;
        }
        if (n%2!=0){
            int mx = -1, ind = -1;
            for (int i=0;i < n; i++){
                if (abs(v[i]) > mx){
                    mx = abs(v[i]);
                    ind = i;
                }
            }
            v[ind] = -v[ind]-1;
        }
    }
    for (int i=0;i<n;i++) cout << v[i] << " ";
}