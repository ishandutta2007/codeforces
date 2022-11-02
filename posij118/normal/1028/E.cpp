#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, ma, pos, zero, skap;
    skap = 0;
    zero = 0;
    ma = 0;
    cin >> n;
    int b[2*n];
    long long a[n];
    for(int i = 0; i<n; i++){
        cin >> b[i];
        if(b[i] == 0) zero++;
        ma = max(ma, b[i]);
        b[n+i] = b[i];
    }

    for(int i = 1; i<=n; i++){
        if(b[i] == ma && b[i-1] != ma){
            pos = (i % n);
            a[pos] = b[pos];
            for(int j = pos + n - 1; j>pos; j--){

                if(skap == 0 && b[j] == 0){
                    a[j % n] = 2 * a[(j + 1) % n] + b[j];
                    skap = 1;
                }
                else a[j % n] = a[(j + 1) % n] + b[j];
            }

            cout << "YES" << endl;
            for(int j = 0; j<n; j++){
                cout << a[j] << " ";
            }
            return 0;
        }

        if(i == n && b[i] > 0){
            cout << "NO";
            return 0;
        }

        if(i == n && b[i] == 0){
            cout << "YES" << endl;
            for(int j = 0; j<n; j++){
                cout << 1 << " ";
            }
            return 0;
        }
    }

}