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

    int m = 750;

    int suf[2*n + 1];
    fill(suf, suf +  2*n + 1, 0);

    int ma[2*n/m + 1], change[2*n/m + 1];
    fill(ma, ma + 2*n/m + 1, 0);
    fill(change, change + 2*n/m + 1, 0);

    int num = 0;
    int q[n];
    for(int i = 0; i<n; i++){
        while(1){
            bool flag = 0;
            for(int j = 0; j<2*n/m + 1; j++){
                if(ma[j] + change[j] > 0){
                    flag = 1;
                    break;
                }
            }

            if(flag) break;

            int pos = 2*(inv[n - 1 - num]);
            num++;

            int block = pos / m;
            for(int j = pos; j >= block * m; j--){
                suf[j]++;
            }

            int mab = -1e9 - 7;
            for(int j = block*m; j < min((block + 1) * m, 2*n + 1); j++){
                mab = max(mab, suf[j]);
            }
            ma[block] = mab;

            for(int j = block - 1; j>=0; j--){
                change[j]++;
            }
        }

        cout << n - num + 1 << " ";

        cin >> q[i];

        int pos = 2*q[i] - 1;
        int block = pos / m;
        for(int j = pos; j >= block * m; j--){
            suf[j]--;
        }

        int mab = -1e9 - 7;
        for(int j = block*m; j < min((block + 1) * m, 2*n + 1); j++){
            mab = max(mab, suf[j]);
        }
        ma[block] = mab;

        for(int j = block - 1; j>=0; j--){
            change[j]--;
        }
    }




}