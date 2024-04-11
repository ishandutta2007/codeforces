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
ll n,m,T,k;

vector<ll> A;
vector<ll> rem;

vector<ll> slut;

vector<ll> B;

ll TWO[55] = {0};
ll F[55] = {0};

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c;
    cin >> n;

    ll t = 1;
    for(ll c1 = 0; c1 < 55; c1++){
        TWO[c1] = t;
        t *= 2;
    }

    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
        bool yes = 0;
        for(ll c2 = 0; c2 < 55; c2++){
            if(a == TWO[c2]){
                yes = 1;
                F[c2]++;
            }
        }
        if(!yes)rem.push_back(a);
    }
    for(ll c1 = 1; c1 < 55; c1++){
        while(F[c1] > F[c1-1]){
            F[c1]--;
            rem.push_back(TWO[c1]);
        }
    }

    for(ll c1 = 0; c1 < 54; c1++){
        for(ll c2 = 0; c2 < F[c1]-F[c1+1]; c2++){
            B.push_back(TWO[c1]);
            slut.push_back(-1);
        }
    }

    sort(all(rem));


    bool fail = 0;

    ll r = ll(B.size())-1;

    ll kr = 0;
    if(r == -1)fail = 1;
    if(rem.size() > 0 && B.size() > 0){
        for(ll c1 = B.size()-1; c1 >= B.size()-rem.size(); c1--){

            slut[c1] = rem[rem.size()-1-kr];
            kr++;
            r--;
            if(slut[c1] > 2*B[c1])fail = 1;
            //cout << slut[c1] << " " << B[c1] << "\n";
        }
        if(rem.size() > B.size())fail = 1;
    }
    if(fail){
        cout << "-1\n";
    }
    else{
        vector<ll> solns;

        solns.push_back(B.size());


        if(fail){
            cout << "-1\n";
        }
        else{

            ll prev = B[0];
            ll skit = 0;
            for(ll c1 = 0; c1 < B.size()-1; c1++){
                while(B[c1] > 0){
                    B[c1]/=2;
                    r--;
                }

                if(r >= c1){
                    solns.push_back(B.size()-1-c1);
                }
                else{
                    break;
                }

            }

            sort(all(solns));
            for(ll c1 = 0; c1 < solns.size(); c1++){
                cout << solns[c1] << " ";
            }

        }
    }

    return 0;
}