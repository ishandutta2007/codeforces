#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    int n;
    ll x;
    cin >> n >> x;
    char op;
    ll sk;
    ll kid = 0;
    for(int i = 0;i<n;i++){
        cin >> op >> sk;
        if(op == '+'){
            x+=sk;
        }
        else{
            if(x - sk >=0){
                x-=sk;
            }
            else{
                kid++;
            }
        }
    }
    cout << x << " " <<kid;
    return 0;
}