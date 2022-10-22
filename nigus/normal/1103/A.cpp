#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

ll n,m,T,k,q;
const ll big = 1000000007;
const ll big2 = 998244353;

ll M[4][4] = {0};

vector<pii> ANS;

bool inbounds(ll i, ll j){
    return i >= 0 && j >= 0 && i < 4 && j < 4;
}

void clearm(){

    for(int c1 = 0; c1 < 4; c1++){
        ll ones = 0;
        for(int c2 = 0; c2 < 4; c2++){
            ones += (M[c1][c2] == 1);
        }
        if(ones == 4){
            for(int c2 = 0; c2 < 4; c2++){
                M[c1][c2] = 2;
            }
        }
    }

    for(int c1 = 0; c1 < 4; c1++){
        ll ones = 0;
        for(int c2 = 0; c2 < 4; c2++){
            ones += (M[c2][c1] != 0);
        }
        if(ones == 4){
            for(int c2 = 0; c2 < 4; c2++){
                M[c2][c1] = 2;
            }
        }
    }
    for(int c1 = 0; c1 < 4; c1++){
        for(int c2 = 0; c2 < 4; c2++){
            if(M[c1][c2] == 2)M[c1][c2] = 0;
        }
    }


}

void place(ll dx, ll dy){

    if(dx == 1){

        if(M[0][0] == 0){
            M[0][0] = 1;
            M[1][0] = 1;
            ANS.push_back({0,0});
            clearm();
            return;
        }
        if(M[2][0] == 0){
            M[2][0] = 1;
            M[3][0] = 1;
            ANS.push_back({2,0});
            clearm();
            return;
        }
    }
    else{
        for(int c1 = 0; c1 < 4; c1++){
            if(M[c1][2] == 0){
                M[c1][2] = 1;
                M[c1][3] = 1;
                ANS.push_back({c1,2});
                clearm();
                return;
            }
        }


    }

    for(int c1 = 0; c1 < 4; c1++){
        for(int c2 = 0; c2 < 4; c2++){
            if(M[c1][c2] == 0 && inbounds(c1+dx,c2+dy) && M[c1+dx][c2+dy] == 0){
                ANS.push_back({c1,c2});
                M[c1][c2] = 1;
                M[c1+dx][c2+dy] = 1;
                clearm();
                return;
            }
        }
    }

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    string s;
    cin >> s;

    for(int c1 = 0; c1 < s.length(); c1++){
        if(s[c1] == '0'){
            place(1,0);
        }
        else{
            place(0,1);
        }
        cout << ANS[c1].first+1 << " " << ANS[c1].second+1 << "\n";
    }



    return 0;
}