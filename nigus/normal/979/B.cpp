#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,q;
ll T;

string name[3] = {"Kuro", "Shiro", "Katie"};
ll ANS[3] = {0};
ll F[52][3] = {0};
ll N[3] = {0};

ll num(char ch){

    if(ch < 'a')return ch-'A';
    return ch-'a'+26;
}

ll solve(int i){
    ll ans = 0;
    for(int c1 = 0; c1 < 52; c1++){
        ll rest = N[i]-F[c1][i];
        ll temp;
        if(rest >= n){
            temp = F[c1][i]+n;
        }
        else{
            temp = N[i];
            if(rest == 0 && n == 1)temp--;
        }
        ans = max(ans,temp);
    }
    return ans;
}

int main() {

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;
    cin >> n;
    for(int c1 = 0; c1 < 3; c1++){
        string s;
        cin >> s;
        N[c1] = s.length();
        for(int c2 = 0; c2 < N[c1]; c2++){
            F[num(s[c2])][c1]++;
        }
        ANS[c1] = solve(c1);
    }
    //cout << ANS[0] << " " << ANS[1] << " " << ANS[2] << "\n";

    if(ANS[0] > ANS[1] && ANS[0] > ANS[2]){
        cout << name[0] << "\n";
        return 0;
    }
    if(ANS[1] > ANS[0] && ANS[1] > ANS[2]){
        cout << name[1] << "\n";
        return 0;
    }
    if(ANS[2] > ANS[1] && ANS[2] > ANS[0]){
        cout << name[2] << "\n";
        return 0;
    }
    cout << "Draw\n";

    return 0;
}