#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll big = 1000000007;

ll n,m,k,T;

struct mq{
    vector<ll> V;
    void in(ll i){
        while(1){
            if(V.size() == 0){
                V.push_back(i);
                return;
            }
            if(V[sz(V)-1] > i){
                V.push_back(i);
                return;
            }
            V.pop_back();
        }
    }
};

vector<ll> A;
vector<ll> I;

ll pek[100003] = {0};
ll pek2[100003] = {0};

bool mark[100003] = {0};


ll stupid(){

    ll ans = -1;
    ll i = 0;
    for(ll c1 = 1; c1 < n+1; c1++){
        ll temp = 0;
        ll ma = 0;
        for(ll c2 = 1; c2 < n+1; c2++){
            if(c2 != c1){
                if(ma < A[c2]){
                    temp++;
                    ma = A[c2];
                }
            }
        }
        if(temp > ans || (temp == ans && A[c1] < i)){
            ans = temp;
            i = A[c1];
        }
    }
    return i;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n;
    A.push_back(0);

    vector<ll> B;
    for(ll c1 = 0; c1 < n; c1++)B.push_back(c1+1);
    random_shuffle(all(B));

    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
       // a = B[c1];
        A.push_back(a);
    }

    A.push_back(n+1);
    for(ll c1 = 0; c1 < n+2; c1++)I.push_back(0);
    for(ll c1 = 0; c1 < n+2; c1++)I[A[c1]] = c1;
    mq Q1;
    Q1.in(n+1);
    ll prev = n+1;
    pek[n+1] = -1;
    for(ll c1 = n; c1 >= 0; c1--){
        Q1.in(A[c1]);
        pek[c1] = I[Q1.V[sz(Q1.V)-2]];
    }

    ll ans = 0;
    ll ma = 0;
    ll chain = 0;

    ll notc = -1;

    for(ll c1 = 1; c1 < n+1; c1++){
        if(A[c1] > ma){
            ma = A[c1];
            mark[c1] = 1;
            chain++;
        }
        else{

            if(notc == -1){
                notc = c1;
            }
        else{
            if(A[notc] > A[c1])notc = c1;
        }
        }
    }
    mark[0] = 1;
    if(notc == -1){
        cout << A[1] << "\n";
    }
    else{
        ll rec = chain;
        ans = notc;

        for(ll c1 = 0; c1 < n+1; c1++){
            if(mark[c1]){
                a = pek[c1];
                b = pek[a];
                if(a != b){
                    ll ext = 0;
                    ll ma = A[c1];
                    for(ll c2 = a+1; c2 < b; c2++){
                        if(A[c2] > ma){
                            ext++;
                            ma = A[c2];
                        }
                    }
                    if(ext+chain-1 > rec || (ext+chain-1 == rec && A[a] < A[ans])){
                        rec = ext+chain-1;
                        ans = a;
                    }
                }
            }
        }
        //cout << A[ans] << " " << stupid() << "\n";
        cout << A[ans] << "\n";
    }

    return 0;
}