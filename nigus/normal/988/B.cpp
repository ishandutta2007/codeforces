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

int n,m,k,q,p;
ll T;

vector<string> S;

bool subs(string s1, string s2){
bool ans = 0;

for(int c1 = 0; c1 < ll(s2.length())-ll(s1.length())+1; c1++){
    bool ans2 = 1;
    for(int c2 = c1; c2 < s1.length()+c1; c2++){
        if(s1[c2-c1] != s2[c2])ans2 = 0;
    }
    //cout <<s1 << " " << s2 << "   " << ans2 << "  "<< c1 << "\n";
    ans |= ans2;
}
return ans;
}

bool comp(string s1, string s2){return s1.length() < s2.length();}

int main() {

    //ios_base::sync_with_stdio(0);
   // cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b,c;

    cin >> n;
    string s;
    for(int c1 = 0; c1 < n; c1++){
        cin >> s;
        S.push_back(s);
    }
    sort(all(S),comp);
    bool ans = 1;
    for(int c1 = 1; c1 < n; c1++){
        if(!subs(S[c1-1],S[c1]))ans = 0;
    }

    if(!ans){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        for(int c1 = 0; c1 < n; c1++){
            cout << S[c1] << "\n";
        }
    }

    return 0;
}