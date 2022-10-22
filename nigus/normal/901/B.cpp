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
typedef vector<ll> vl;

const ll big = 1000000007;

ll n,m,k,T;

vector<vector<ll> > P;

vector<ll> ANS;
vector<ll> ANS2;

bool check(vector<ll> V, ll i){
    for(ll c1 = 0; c1 < V.size(); c1++){
        if(abs(V[c1]) != 1 && abs(V[c1]) != 0)return 0;
    }
    if(sz(V) != i+1)return 0;
    if(V[i] != 1)return 0;
    return 1;
}


void dfs(vector<ll> A1, vector<ll> A2){

    if(sz(A1) == n+1){
        ANS = A1;
        ANS2 = A2;

        return;
    }

    vector<ll> P2;
    for(ll c2 = 0; c2 < sz(A1)+1; c2++){
        ll a = 0;
        ll a1 = c2-1;

        if(a1 >= 0 && a1 < sz(A1)){
            a += A1[a1];

        }
        if(c2 < sz(A2)){
            a += A2[c2];

        }
        P2.push_back(a);
    }
    if(check(P2, sz(A1)))dfs(P2,A1);

    P2.clear();
    for(ll c2 = 0; c2 < sz(A1)+1; c2++){
        ll a = 0;
        ll a1 = c2-1;

        if(a1 >= 0 && a1 < sz(A1)){
            a += A1[a1];

        }
        if(c2 < sz(A2)){
            a -= A2[c2];

        }
        P2.push_back(a);
    }
    if(check(P2, sz(A1)))dfs(P2,A1);
    return;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n;

    if(n == 1){

        cout << "1\n0 1\n0\n1\n";
            return 0;
    }
    /*
    if(n == 2){
        cout << "2\n-1 0 1\n1\n0 1\n";
        return 0;
    }
*/


    vector<ll> P1;


    vector<ll> P3;


    for(ll c1 = -1; c1 <= 1; c1++){
        for(ll c2 = -1; c2 <= 1; c2++){
            for(ll c3 = -1; c3 <= 1; c3++){

                        P1.clear();
                        P3.clear();
                        if(c1 == 0)continue;
                        if(sz(ANS) > 0)break;
                        P1.push_back(c1);
                        P3.push_back(c2);
                        P3.push_back(c3);
                        dfs(P1,P3);

            }
        }
    }


    if(sz(ANS) > 0){
        cout << sz(ANS)-1 << "\n";
        for(ll c1 = 0; c1 < sz(ANS); c1++){
            cout << ANS[c1] << " ";
        }
        cout <<"\n"<< sz(ANS2)-1 << "\n";
        for(ll c1 = 0; c1 < sz(ANS2); c1++){
            cout << ANS2[c1] << " ";
        }
    }
    else{
        cout << "-1\n";
    }


    return 0;
}