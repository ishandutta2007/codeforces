#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int sk[n];
    int mx,mi;
    mi = pow(10,9);
    mx = 0;
    for(int i = 0;i<n;i++){
        cin >> sk[i];
        if(sk[i] > mx){
            mx = sk[i];
        }
        if(sk[i] < mi){
            mi = sk[i];
        }
    }
    int am = 0;
    for(int i = 0;i<n;i++){
        if(sk[i] > mi && sk[i] < mx){
            am++;
        }
    }
    cout << am;
    return 0;
}