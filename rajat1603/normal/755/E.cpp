#include "bits/stdc++.h"
using namespace std;
int n;
int k;
int main(){
    cin >> n >> k;
    if(n < 4){
        cout << -1 << endl;
    }
    else if(k == 1){
        cout << -1 << endl;
    }
    else if(k == 2){
        if(n == 4){
            cout << -1 << endl;
        }
        else{
            cout << n - 1 << endl;
            for(int i = 1 ; i < n ; ++i){
                cout << i << " " << i + 1 << endl;
            }
        }
    }
    else if(k == 3){
        if(n < 4){
            cout << -1 << endl;
        }
        else if(n == 4){
            cout << 3 << endl;
            cout << 1 << " " << 2 << endl;
            cout << 2 << " " << 3 << endl;
            cout << 3 << " " << 4 << endl;
        }
        else{
            cout << 3 + (n - 4) * 3 + (n - 4) * (n - 5) / 2 << endl;
            cout << 1 << " " << 2 << endl;
            cout << 2 << " " << 3 << endl;
            cout << 3 << " " << 4 << endl;
            for(int i = 1 ; i <= 3 ; ++i){
                for(int j = 5 ; j <= n ; ++j){
                    cout << i << " " << j << endl;
                }
            }
            for(int i = 5 ; i <= n ; ++i){
                for(int j = i + 1 ; j <= n ; ++j){
                    cout << i << " " << j << endl;
                }
            }
        }
    }
    else{
        cout << -1 << endl;
    }
}