#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
int n,m,q,T,k;

vector<vector<ll> > C(1000001 , vector<ll>());
ll deg[1000001] = {0};
ll deg2[1000001] = {0};

bool mark[1000001] = {0};

void check(ll i, ll par){
    mark[i] = 1;
    for(ll c1 = 0; c1 < deg[i]; c1++){
        ll a = C[i][c1];
        if(a != par && mark[a] == 0){
            check(a,i);
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    int a,b,c;
    ll sings = 0;
    ll edges = 0;
    scanf("%d %d" , &n, &m);
    for(ll c1 = 0; c1 < m; c1++){
        scanf("%d %d" , &a , &b);
        a--;
        b--;
        deg[a]++;
        deg[b]++;
        C[a].push_back(b);
        C[b].push_back(a);
        if(a == b){
            sings++;
        }
        else{
            deg2[a]++;
            deg2[b]++;
            edges++;
        }
    }
    bool checked = 0;
    bool fail = 0;
    for(ll c1 = 0; c1 < n; c1++){
        if(deg[c1] == 0){
            mark[c1] = 1;
        }
        else{
            if(!mark[c1]){
                if(!checked){
                    check(c1,-1);
                    checked = 1;
                }
                else{
                    fail = 1;
                }
            }
        }
    }

    if(fail){
        cout << "0\n";
    }
    else{
        ll ans = 0;
        ans += (sings*(sings-1))/2;
        ans += sings*edges;


        ll ans2 = 0;

        for(ll c1 = 0; c1 < n; c1++){
            ans += (deg2[c1]*(deg2[c1]-1)) / 2;
        }
        cout << ans << "\n";

    }

    return 0;
}