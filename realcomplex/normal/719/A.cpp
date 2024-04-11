#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int sk[n];
    for(int j = 0;j<n;j++){
        cin >> sk[j];
        if(j >= 1){
            if(abs(sk[j]-sk[j-1]) != 1){
                cout << -1;
                exit(0);
            }
        }
    }
    if(n == 1){
        if(sk[0] == 0){
            cout << "UP";
        }
        else if(sk[0] == 15){
            cout << "DOWN";
        }
        else{
            cout << -1;
        }
        exit(0);
    }
    int l = sk[n-1];
    if(sk[n-1]>sk[n-2]){
        if(l == 15){
            cout << "DOWN";
        }
        else{
            cout << "UP";
        }
    }
    else{
        if(l == 0){
            cout << "UP";
        }
        else{
            cout << "DOWN";
        }
    }
    return 0;
}