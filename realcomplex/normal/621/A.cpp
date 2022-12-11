#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define fi first
#define se second

int main(){

    int n;
    cin >> n;
    ll sk;
    ll sum = 0;
    ll m = INF;
    for(int j = 0;j<n;j++){
        cin >> sk;
        sum += sk;
        if(sk%2==1){
            m = min(m,sk);
        }
    }
    if(sum%2==0){
        cout << sum;
    }
    else{
        cout << sum-m;
    }
    return 0;
}