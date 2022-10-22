#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,q,T,k;
ll p;
vector<ll> A;
vector<ll> B;
vector<ll> ind;
vector<ld> TI;

bool test(ld x){
ld sumd = 0;
for(ll c1 = 0; c1 < n; c1++){
    if(TI[c1] <= x){
        sumd += ld(x * ld(A[c1]) - ld(B[c1]))/ld(p);
    }
}
return sumd <= x;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

   ll a,b,c;

   cin >> n >> p;
    ll suma = 0;
   for(ll c1 = 0; c1 < n; c1++){
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
        suma += a;
        ind.push_back(c1);
        TI.push_back(ld(b)/ld(a));
   }

   ld uplim = 1;
   ll tries = 0;

   while(tries < 100){
        if(!test(uplim))break;
        uplim *= 2;
        tries++;
   }
    if(suma <= p)tries = 100;

   if(tries == 100){
        cout << -1 << "\n";
   }
   else{

    ld l = 0;
    ld r = uplim;

    while(r-l >= 0.0000001){

        ld mid = (l+r)/2;
        if(test(mid)){
            l = mid;
        }
        else{
            r = mid;
        }

    }

    cout << setprecision(18) << l << "\n";

   }
    return 0;
}