#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll big = 1000000007ll;
const ll big2 = 1000000009ll;
ll n,m,k,q,h,T;

ll par[26] = {0};
ll nex[26] = {0};

bool seen[26] = {0};

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    for(ll c1 = 0; c1 < 26; c1++)par[c1] = -1;
    for(ll c1 = 0; c1 < 26; c1++)nex[c1] = -1;

    cin >> n;
    bool fail = 0;
    for(ll c1 = 0; c1 < n; c1++){
        string s;
        cin >> s;

        if(s.length() == 1){
            seen[s[0]-'a'] = 1;
        }

        for(ll c2 = 1; c2 < s.length(); c2++){
            a = s[c2-1]-'a';
            b = s[c2]-'a';
            seen[a] = 1;
            seen[b] = 1;
            if(par[b] != -1 && par[b] != a){
                fail = 1;
            }
            else{
                par[b] = a;
            }
            if(nex[a] != -1 && nex[a] != b){
                fail = 1;
            }
            else{
                nex[a] = b;
            }
        }
    }

    ll nseen = 0;
    for(ll c1 = 0; c1 < 26; c1++)nseen += seen[c1];


    string ans = "";

    string alfa = "abcdefghijklmnopqrstuvwxyz";

    bool mark[26] = {0};

    for(ll c1 = 0; c1 < 26; c1++){
        if(seen[c1] && !mark[c1]){
            if(par[c1] == -1){
                mark[c1] = 1;
                ans += alfa[c1];
                a = c1;
                while(nex[a] != -1){
                    a = nex[a];
                    ans += alfa[a];
                    if(mark[a]){fail = 1;break;}
                    mark[a] = 1;
                }
            }
        }
    }

    if(ans.length() != nseen)fail = 1;

    if(fail){
        cout << "NO\n";

    }
    else{
        cout << ans << "\n";
    }

    return 0;
}