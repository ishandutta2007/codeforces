#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,k,q,w,h,x,y;

ll NIM[1000001] = {0};

ll nim(ll i){

    if(i == 0)return 0;
    if(i < 1000001){
        if(NIM[i] != 0)return NIM[i];
    }
    bool mex[100001] = {0};

    for(ll c1 = 1; c1 < 32; c1++){
        ll a = (((1 << (c1-1))-1)&i)|(i >> c1);
        mex[nim(a)] = 1;
        if(i >> c1 == 0)break;
    }
    for(ll c1 = 0; c1 < 1000001; c1++){
        if(!mex[c1]){
            if(i < 1000001)NIM[i] = c1;
            return c1;
        }
    }
}


int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    set<ll> S;
    vector<ll> P;
    vector<ll> A;
    cin >> n;
    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
        for(ll c2 = 2; c2*c2 <= a; c2++){
            if(a%c2 == 0){
                if(S.find(c2) == S.end()){
                    S.insert(c2);
                    P.push_back(c2);
                }
                while(a%c2 == 0)a /= c2;
            }
        }
        if(a != 1){
            if(S.find(a) == S.end()){
                S.insert(a);
                P.push_back(a);
            }
        }
    }

    ll ans = 0;
    for(ll c1 = 0; c1 < sz(P); c1++){
        a = 0;
        for(ll c2 = 0; c2 < n; c2++){
            b = 0;
            while(A[c2]%P[c1] == 0){
                A[c2] /= P[c1];
                b++;
            }
            if(b > 0){
                a |= (1 << (b-1));
            }
        }
        ans ^= nim(a);
    }

    if(ans != 0){
        cout << "Mojtaba\n";
    }
    else{
        cout << "Arpa\n";
    }
    return 0;
}