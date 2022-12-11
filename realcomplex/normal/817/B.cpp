#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(ll sk){
    return ((sk * (sk - 1)) / 2) + sk;
}

int main()
{

    int n;
    cin >> n;
    ll sk[n];
    for(int i = 0;i<n;i++){
        cin >> sk[i];
    }
    sort(sk,sk + n);
    ll eq = 1;
    for(int i = 1;i<n;i++){
        if(sk[i] == sk[i - 1]){
            eq++;
        }
        else{
            break;
        }
    }
    ll eq2 = 1;
    for(int i = 2;i<n;i++){
        if(sk[i] == sk[i - 1]){
            eq2++;
        }
        else{
            break;
        }
    }
    int eq3 = 1;
    for(int i = 3;i<n;i++){
        if(sk[i] == sk[i - 1]){
            eq3++;
        }
        else{
            break;
        }
    }
    if(eq > 3){
        ll sum = 0;
        for(int i = 2;i<=eq;i++){
            sum += f(eq - i);
        }
        cout << sum;
    }
    else if(eq2 > 2){
        cout << f(eq2 - 1);
    }
    else if(eq3 > 1){
        cout << eq3;
    }
    else{
        cout << 1;
    }
    return 0;
}