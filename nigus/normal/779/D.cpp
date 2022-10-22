#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
ll n,m,q,T,k;

string s;
string ss;
ll P[200001] = {0};

bool check(ll i){
ll p = 0;
for(ll c1 = 0; c1 < n; c1++){
    if(P[c1] > i && s[c1] == ss[p])p++;
    if(p == m)return 1;
}
return 0;
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll c1,c2,c3;
    ll a,b,c;

    cin >> s;
    cin >> ss;
    n = s.length();
    m = ss.length();
    for(c1 = 0; c1 < n; c1++){
        cin >> a;
        P[a-1] = c1+1;
    }

    ll l = 0;
    ll r = n;

    while(l < r-1){
        ll mid = (l+r)/2;
        if(check(mid)){
            l = mid;
        }
        else{
            r = mid;
        }
    }

    cout << l << "\n";

    return 0;
}