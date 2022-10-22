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
ll n,m,T,k,q;

ll M[10][10] = {0};

bool check(){

for(ll c1 = 0; c1 < 10; c1++){
    for(ll c2 = 0; c2 < 6; c2++){
        if(M[c1][c2] * M[c1][c2+1] * M[c1][c2+2] * M[c1][c2+3] * M[c1][c2+4] == 1){
            return 1;
        }
    }
}

for(ll c2 = 0; c2 < 10; c2++){
    for(ll c1 = 0; c1 < 6; c1++){
        if(M[c1][c2] * M[c1+1][c2] * M[c1+2][c2] * M[c1+3][c2] * M[c1+4][c2] == 1){
            return 1;
        }
    }
}

for(ll c1 = 0; c1 < 6; c1++){
    for(ll c2 = 0; c2 < 6; c2++){
        if(M[c1][c2] * M[c1+1][c2+1] * M[c1+2][c2+2] * M[c1+3][c2+3] * M[c1+4][c2+4] == 1){
            return 1;
        }
    }
}

for(ll c1 = 4; c1 < 10; c1++){
    for(ll c2 = 0; c2 < 6; c2++){
        if(M[c1][c2] * M[c1-1][c2+1] * M[c1-2][c2+2] * M[c1-3][c2+3] * M[c1-4][c2+4] == 1){
            return 1;
        }
    }
}
return 0;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    for(ll c1 = 0; c1 < 10; c1++){
        string s;
        cin >> s;
        for(ll c2 = 0; c2 < 10; c2++){
            if(s[c2] == 'X'){
                M[c1][c2] = 1;
            }
            if(s[c2] == 'O'){
                M[c1][c2] = 2;
            }
        }
    }
    string ans = "NO";
    for(ll c1 = 0; c1 < 10; c1++){
        for(ll c2 = 0; c2 < 10; c2++){
            if(M[c1][c2] == 0){
                M[c1][c2] = 1;
                if(check())ans = "YES";
                M[c1][c2] = 0;
            }
        }
    }
    cout << ans << "\n";

    return 0;
}