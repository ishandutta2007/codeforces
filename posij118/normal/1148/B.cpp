#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;

    long long a[n], b[m];
    pair<long long, int> c[n + m + 1];
    c[n + m] = {3*1e9, 0};

    for(int i = 0; i<n; i++){
        cin >> a[i];
        c[i] = {a[i] + ta, 0};
    }

    for(int j = 0; j<m; j++){
        cin >> b[j];
        c[n + j] = {b[j], 1};
    }

    sort(c, c + n + m + 1);

    int cnta, cntb;
    cnta = 0;
    cntb = 0;
    long long mi = -1;

    for(int i = 0; i<m + n + 1; i++){
        if(c[i].second == 0){
            cnta++;
            if(cnta <= k + 1){
                int rem = k - cnta + 1;



                if(rem + cntb >= m){
                    cout << -1;
                    return 0;
                }

                else mi = max(mi, b[cntb + rem] + tb);

            }
        }

        else{
            cntb++;
        }
    }

    cout << mi;

}