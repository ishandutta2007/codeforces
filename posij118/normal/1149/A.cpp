#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    int cnt = 0;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        if(a[i] == 1) cnt++;
    }

    if(n == 1){
        cout << a[0];
    }

    else if(cnt % 2 && cnt > 1){
        for(int i = 0; i<cnt; i++){
            cout << 1 << " ";
        }

        for(int i = 0; i<n - cnt; i++){
            cout << 2 << " ";
        }
    }

    else if(cnt == 1){
            cout << 2 << " ";

            for(int i = 0; i<cnt; i++){
                cout << 1 << " ";
            }

            for(int i = 0; i<n - cnt - 1; i++){
                cout << 2 << " ";
            }
    }

    else if(cnt > 2){
        for(int i = 0; i<cnt - 1; i++){
            cout << 1 << " ";
        }

        for(int i = 0; i<n - cnt; i++){
            cout << 2 << " ";
        }
        cout << 1 << " ";
    }

    else if(cnt == 2){
        if(n == 2){
            cout << 1 << " " << 1;
        }

        else{
            cout << 2 << " ";
            for(int i = 0; i<cnt - 1; i++){
                cout << 1 << " ";
            }

            for(int i = 0; i<n - cnt - 1; i++){
                cout << 2 << " ";
            }

            cout << 1;

        }
    }

    else{
        for(int i = 0; i<n; i++){
            cout << 2 << " ";
        }
    }
}