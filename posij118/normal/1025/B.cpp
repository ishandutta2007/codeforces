#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n], b[n];
    for(int i = 0; i<n; i++){
        cin >> a[i] >> b[i];
    }

    if(n == 1){
        cout << a[0];
        return 0;
    }

    for(int i = 2; i<50000; i++){
        while((a[0] % i) == 0){
            a[0]/=i;
            for(int j = 1; j<n; j++){
                if(a[j] % i != 0 && b[j] % i != 0) break;
                if(j == n - 1){
                    cout << i;
                    return 0;
                }
            }
        }

        while((b[0] % i) == 0){
            b[0]/=i;
            for(int j = 1; j<n; j++){
                if(a[j] % i != 0 && b[j] % i != 0) break;
                if(j == n - 1){
                    cout << i;
                    return 0;
                }
            }
        }
    }

    if(a[0] > 1){
        for(int j = 1; j<n; j++){
                if(a[j] % a[0] != 0 && b[j] % a[0] != 0) break;
                if(j == n - 1){
                    cout << a[0];
                    return 0;
                }
            }
    }

    if(b[0] > 1){
        for(int j = 1; j<n; j++){
                if(a[j] % b[0] != 0 && b[j] % b[0] != 0) break;
                if(j == n - 1){
                    cout << b[0];
                    return 0;
                }
            }
    }

    cout << -1;



}