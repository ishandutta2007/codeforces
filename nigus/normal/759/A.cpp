#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll big = 1000000007ll;
ll n,m,k,x,y;


bool mark[200001];
vector<ll> P;
vector<ll> B;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll c1,c2,c3,c4,c5;
    ll a,b,c;

    cin >> n;

    for(c1 =0; c1 < n; c1++){
        cin >> a;
        a--;
        P.push_back(a);
    }
    ll sumb = 0;
    for(c1 =0; c1 < n; c1++){
        cin >> a;
        B.push_back(a);
        sumb+=a;
    }
    sumb++;
    sumb%=2;
    ll nc = 0;
    for(c1 = 0; c1 < n; c1++){
        if(mark[c1] == 0){
            nc++;
            a = P[c1];
            mark[a] = 1;
            while(a != c1){
                a = P[a];
                mark[a] = 1;
            }
        }
    }

    cout << nc - (nc == 1) + sumb << "\n";

    return 0;
}