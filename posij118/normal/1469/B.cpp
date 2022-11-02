#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n;

        int r[n], pr[n + 1];
        int ma = 0;
        pr[0] = 0;
        for(int i = 0; i<n; i++){
            cin >> r[i];
            pr[i + 1] = pr[i] + r[i];
            ma = max(ma, pr[i + 1]);
        }

        cin >> m;
        int b[m], pb[m + 1];
        int maa = 0;
        pb[0] = 0;
        for(int i = 0; i<m; i++){
            cin >> b[i];
            pb[i + 1] = pb[i] + b[i];
            maa = max(maa, pb[i + 1]);
        }

        cout << ma + maa << endl;


    }

}