#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
ll n,m,q,T;

ll A[6] = {0};
ll B[6] = {0};

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll c1,c2,c3;
    ll a,b,c;

    cin >> n;

    for(c1 = 0; c1 < n; c1++){
        cin >> a;
        A[a]++;
    }

    for(c1 = 0; c1 < n; c1++){
        cin >> a;
        B[a]++;
    }

    ll ans = 0;
    ll yes = 0;
    for(c1 = 1; c1 < 6; c1++){
        if((A[c1]+B[c1])%2 == 1){
            yes = -1;
        }
        else{
            ans += abs(A[c1]-B[c1])/2;
        }
    }

    if(yes == -1){
        cout << "-1\n";
    }
    else{
        cout << ans/2 << "\n";
    }

    return 0;
}