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

ll TWO[16] = {0};

vector<ll> AC;
vector<ll> A;
vector<ll> B;
vector<ld> da;

vector<ll> ind;
vector<ll> tid;
vector<ld> sc;

ll mod(ll x, ll i){
if(x < 0)return mod(i-mod(-x,i),i);
return x % i;
}

ll score(ll a, ll b){
    ll ans = 3000;
    for(ll c1 = 32; c1 > 0; c1 /= 2){
        if(c1*a <= b)return ans;
        ans-= 500;
    }
    return 500;
}

ll when(ll a, ll b, ll i, ll x){
    if(i == 0){
        return max(0ll,TWO[x]*a-b);
    }
    else{
        //cout << a << " " << b << "\n";
        return max(0ll,(b - TWO[x+1]*a - 1) / (TWO[x+1]-1));
    }
}

bool comp(ll i, ll j){
    return tid[i] < tid[j];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;
    ll t = 1;
    for(ll c1 = 0; c1 < 16; c1++){
        TWO[c1] = t;
        t *= 2;
    }
    cin >> n;
    ld sc1 = 0;
    ld sc2 = 0;
    for(ll c1 = 0; c1 <5; c1++){
        AC.push_back(0);
        da.push_back(0);
    }

    for(ll c1 = 0; c1 < n; c1++){
        for(ll c2 = 0; c2 < 5; c2++){
            cin >> a;
            if(c1 == 0){
                A.push_back(a);
                if(a != -1)
                    da[c2] += 1.0 - ld(a)/ld(250);
            }
            if(c1 == 1){
                B.push_back(a);
                if(a != -1)
                    da[c2] -= 1.0 - ld(a)/ld(250);
            }
            if(a != -1)AC[c2]++;
        }
    }

    for(ll c1 = 0; c1 < 5; c1++){
        if(A[c1] != -1){
            sc1 += (score(AC[c1],n)/250) * (250 - A[c1]);
        }
    }

    for(ll c1 = 0; c1 < 5; c1++){
        if(B[c1] != -1){
            sc2 += (score(AC[c1],n)/250) * (250 - B[c1]);
        }
    }

    for(ll c1 = 0; c1 < 5; c1++){

        if(A[c1] == -1 || B[c1] == -1 || da[c1] > 0){
            for(ll c2 = 0; c2 < 6; c2++){
                ll w = when(AC[c1], n, 0, c2);
                if(w > 0){
                    ind.push_back(ind.size());
                    tid.push_back(w);
                    sc.push_back(da[c1] * 500.0);
                    //cout << w << " " << sc[sc.size()-1] << "  -  " << c1 << "\n";
                }
            }
        }
        else{

            for(ll c2 = 0; c2 < 6; c2++){
                ll w = when(AC[c1], n, 1, c2);
                if(w > 0){
                    ind.push_back(ind.size());
                    tid.push_back(w);
                    sc.push_back(-da[c1] * 500.0);
                    //cout << w << " " << sc[sc.size()-1] << " " << c2 << "\n";
                }
            }
        }
    }

    sort(all(ind) , comp);
    ll ans = -1;

    ld sc3 = sc1-sc2;

    ll prev = -1;


    if(sc3 > 0){
        cout << "0\n";
    }
    else{
        for(ll c1 = 0; c1 < ind.size(); c1++){
            a = ind[c1];
            //cout << sc3 << " " << tid[a] << "\n";
            sc3 += sc[a];
            bool yes = 0;
            if(c1 == ind.size()-1){
                yes = 1;
            }
            else{
                if(tid[a] != tid[ind[c1+1]])yes = 1;
            }

            if(yes){
                ld eps = 0.0000000001;
                if(sc3 > eps){
                    ans = tid[a];
                    break;
                }
            }

            prev = tid[a];
        }

        cout << ans << "\n";
    }
    return 0;
}