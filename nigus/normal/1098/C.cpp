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

ll n,m,T,k;
const ll big = 1000000007;
const ll big2 = 998244353;

priority_queue<pll> pq;
ll parent[100001] = {0};
ll outdeg[100001] = {0};
ll H[100001] = {0};
ll tot = 0;
ll branch;

vl leaves;
vl targets;

ll upd = 0;
ll F[100001] = {0};
ll F2[100001] = {0};

bool comp(ll i, ll j){
    return H[i] < H[j];
}

void moveto(ll i, ll j){

    ll pi = parent[i];
    outdeg[pi]--;
    parent[i] = j;
    outdeg[j]++;
    tot -= H[i];
    H[i] = H[j]+1;
    tot += H[i];
}

void crisis(){
    leaves.clear();
    targets.clear();
    for(int c1 = 0; c1 < n; c1++){
        if(outdeg[c1] == 0)leaves.push_back(c1);
        if(outdeg[c1] != branch)targets.push_back(c1);
    }
    upd++;
    sort(all(leaves),comp);
    sort(all(targets),comp);
    while(!pq.empty()){
        pq.pop();
    }


    for(int c2 = 0; c2 < sz(leaves); c2++){
        ll bottleaf = leaves[c2];
        ll good = -1;
        for(int c1 = 0; c1 < sz(targets); c1++){
            ll a = targets[c1];
            if(a != bottleaf){
                ll dif = H[a]+1-H[bottleaf];
                if(dif+tot == k){
                    moveto(bottleaf,a);
                    return;
                }
                if(dif+tot < k){
                    good = a;
                }
            }
        }
        if(good != -1){
            moveto(bottleaf,good);
            break;
        }
    }

    for(int c1 = 0; c1 < n; c1++){
        if(outdeg[c1] == 0){
            pq.push({-H[c1],c1});
        }
    }
}

void mov(){

    ll i = pq.top().second;
    pq.pop();
    ll j = pq.top().second;
    pq.pop();

    ll diff = k-tot;
    if(H[j]-H[i]+1 > diff){
        crisis();
        return;
    }

    ll pi = parent[i];
    outdeg[pi]--;
    if(outdeg[pi] == 0)pq.push({-H[pi],pi});
    parent[i] = j;
    outdeg[j]++;
    tot -= H[i];
    //cerr << H[i] << " " << H[j] << "\n";
    H[i] = H[j]+1;
    pq.push({-H[i],i});
    tot += H[i];

}

ll minans(ll k2, ll n2){
    if(k2 == 1){
        return (n2*(n2+1))/2;
    }
    ll res = 0;
    ll rest = n2;
    ll t = 1;
    ll its = 1;
    while(1){
        if(t > rest){
            t = rest;
        }
        res += t*its;
        rest -= t;
        if(rest <= 0)break;
        t *= k2;
        its++;
    }
    return res;
}

void gettree(){
    ll p = 0;
    H[0] = 1;
    for(ll c1 = 1; c1 < n; c1++){
        if(outdeg[p] == branch)p++;
        parent[c1] = p;
        H[c1] = H[p]+1;
        outdeg[p]++;
    }

    for(ll c1 = 0; c1 < n; c1++){
        if(outdeg[c1] == 0){
            pq.push({-H[c1],c1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> n >> k;
    bool yes = 0;
    branch = 0;
    if(k > (n*(n+1))/2){
        cout << "No\n";
        return 0;
    }
    for(ll c1 = 1; c1 < n; c1++){
        a = minans(c1,n);
        if(a <= k){
            branch = c1;
            yes = 1;
            break;
        }
    }

    if(!yes){
        cout << "No\n";
        return 0;
    }

    if(branch == 1){
        cout << "Yes\n";
        for(int c1 = 1; c1 < n; c1++){
            cout << c1 << " ";

        }
        return 0;
    }

    tot = minans(branch,n);

    gettree();
    while(tot < k){
      //  cerr << tot << "\n";
        mov();
    }

   // cerr << "tot: " << tot << "   k: " << k << "\n";

    cout << "Yes\n";

    for(int c1 = 1; c1 < n; c1++){
        cout << parent[c1]+1 << " ";
    }
    assert(tot == k);
//cerr << "\ntot: " << tot << "   k: " << k << "\n";
    return 0;
}