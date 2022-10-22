#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,q,m,k,h;
ll T;

ll FAC[100003] = {0};
ll INV[100003] = {0};

ll upp(ll i, ll j){
    if(j == 0)return 1;
    if(j%2 == 0){
        ll h = upp(i,j/2);
        return (h*h)%big;
    }
    return (i * upp(i,j-1))%big;
}

ll bin(ll i, ll j){
if(j > i)return 0;
ll ans = 1;
ans = (FAC[i]*INV[j])%big;
ans *= INV[i-j];
return ans%big;
}

void setup(){
    ll t = 1;
    for(ll c1 = 0; c1 < 100003; c1++){
        FAC[c1] = t;
        INV[c1] = upp(t,big-2);
        t *= c1+1;
        t %= big;
    }
}

ll comp(ll i,ll j){
if(i == 0 && j == 0)return 1;
return bin(i+j-1,j-1);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int c1,c2,c3,c4,c5;
    ll a,b,c,d;

    cin >> n >> m >> h;
    setup();

    ll sumtot = 0;
    ll ans = 0;

    if(m == 0){
        cout << "1\n";

    }
    else{
    for(c1 = 1; c1 <= n+m; c1++){

        a = c1/2;
        b = c1/2+c1%2;

        ll a1 = comp(n-a,a);
        ll b1 = comp(m-b,b);
        sumtot += (a1*b1)%big;
        sumtot%=big;
        ans += a1*comp(m-(h+1)*b , b);
        ans %= big;

        a = c1/2+c1%2;
        b = c1/2;
        //cout << ans << "  " << sumtot << "\n";
        a1 = comp(n-a,a);
        b1 = comp(m-b,b);
        sumtot += (a1*b1)%big;
        sumtot%=big;
        ans += a1*comp(m-(h+1)*b , b);
        ans %= big;
       // cout << ans << "  " << sumtot << "\n";
    }


    cout << (ans * upp(sumtot,big-2))%big << "\n";
    }
    return 0;
}