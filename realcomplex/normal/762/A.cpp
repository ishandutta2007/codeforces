#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll>d;

void getDiv(ll n){
    for(ll i = 1;i<=sqrt(n);i++){
        if(n%i==0){
            d.push_back(i);
            if(n/i != i){
                d.push_back(n/i);
            }
        }

    }
}

int main()
{
    ll n;
    cin >> n;
    getDiv(n);
    int k;
    cin >> k;
    sort(d.begin(),d.end());
    if(d.size()<k){
        cout << -1;
    }
    else{
        cout << d[k-1];
    }
    return 0;
}