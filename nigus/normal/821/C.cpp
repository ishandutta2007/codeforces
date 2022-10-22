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

vector<ll> ST;
vector<ll> magicw;
bool magic[300003] = {0};
bool inst[300003] = {0};

void pb(){
    if(ST.size() == 0)return;
    while(inst[ST[ST.size()-1]] == 0){
        ST.pop_back();
        if(ST.size() == 0)return;
    }
    return;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;

    ll ans = 0;
    ll now = 1;
    for(ll c1 = 0; c1 < 2*n; c1++){
        string s;
        cin >> s;
        if(s == "add"){
            cin >> a;
            ST.push_back(a);
        }
        else{
            if(ST.size() != 0){
                if(ST[ST.size() - 1] == now){
                    ST.pop_back();
                }
                else{
                    ST.clear();
                    ans++;
                }
            }
            now++;
        }

    }

    cout << ans << "\n";

    return 0;
}