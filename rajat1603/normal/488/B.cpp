#include "bits/stdc++.h"
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n == 0){
        cout << "YES\n1\n1\n3\n3";
    }
    else if(n == 1){
        cin >> n;
        cout << "YES\n" << n << "\n" << n + n + n << "\n" << n + n + n ;
    }
    else if(n == 2){
        int b[2];
        int a[4];
        cin >> b[0] >> b[1];
        for(int i = 1 ; i <= 3000 ; ++i){
            for(int j = 1 ; j <= 3000 ; ++j){
                a[0] = b[0];
                a[1] = b[1];
                a[2] = i;
                a[3] = j;
                sort(a , a + 4);
                if(a[0] + a[1] + a[2] + a[3] == a[1] + a[1] + a[2] + a[2] && a[0] + a[1] + a[2] + a[3] == (a[3] << 2) - (a[0] << 2)){
                    cout << "YES\n" << i << "\n" << j;
                    return 0;
                }
            }
        }
        cout << "NO";
    }
    else if(n == 3){
        int b[3];
        int a[4];
        cin >> b[0] >> b[1] >> b[2];
        for(int i = 1 ; i <= 10000 ; ++i){
            a[0] = b[0];
            a[1] = b[1];
            a[2] = b[2];
            a[3] = i;
            sort(a , a + 4);
            if(a[0] + a[1] + a[2] + a[3] == a[1] + a[1] + a[2] + a[2] && a[0] + a[1] + a[2] + a[3] == (a[3] << 2) - (a[0] << 2)){
                cout << "YES\n" << i;
                return 0;
            }
        }
        cout << "NO";
    }
    else{
        int a[4];
        for(int i = 0 ; i < 4 ; ++i){
            cin >> a[i];
        }
        sort(a , a + 4);
        if(a[0] + a[1] + a[2] + a[3] == a[1] + a[1] + a[2] + a[2] && a[0] + a[1] + a[2] + a[3] == (a[3] << 2) - (a[0] << 2)){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
    }
}