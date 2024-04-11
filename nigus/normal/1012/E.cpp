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
typedef pair<double,double> pdd;


const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k,T,q;

vl A,A2;
map<ll,ll> M;

ll d = 0;

ll pek[200001] = {0};
ll deg[200001] = {0};

ll par(ll i){
    ll i2 = i;
    while(i2 != pek[i2]){
        i2 = pek[i2];
    }
    return i2;
}

void merg(ll i, ll j){
    ll i2 = par(i);
    ll j2 = par(j);
    if(i2 != j2){
        if(deg[i2] < deg[j2])swap(i2,j2);
        deg[i2] += deg[j2];
        pek[j2] = i2;
    }
}

vl extramove;

vl thing;

vector<set<ll> > C(400001, set<ll>());

ll indeg[400001] = {0};
ll outdeg[400001] = {0};

vector<vl> anses;

vl eulertour(int i){
    vl ANS;
    vl vts;
    ll j = i;
    while(outdeg[j] > 0){
        vts.push_back(j);
        ll j2 = j;
        j = *(C[j].begin());
        C[j2].erase(j);
        outdeg[j2]--;
        indeg[j]--;
    }
    ANS.push_back(i);
    for(int c1 = 1; c1 < sz(vts); c1++){
        vl nt = eulertour(vts[c1]);
        for(int c2 = 0; c2 < sz(nt); c2++){
            ANS.push_back(nt[c2]);
        }
        if(sz(nt) > 1){
            ANS.push_back(vts[c1]);
        }
    }
    return ANS;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c;

    cin >> n >> m;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
        A2.push_back(a);
    }
    sort(all(A2));
    for(int c1 = 0; c1 < n; c1++){
        if(M.find(A2[c1]) == M.end()){
            M[A2[c1]] = d;
            d++;
        }
    }

    for(int c1 = 0; c1 < n; c1++){
        A[c1] = M[A[c1]];
        A2[c1] = M[A2[c1]];
    }

    ll nonfix = 0;
    for(int c1 = 0; c1 < n; c1++){
        if(A[c1] != A2[c1])nonfix++;
    }

    if(m < nonfix){
        cout << "-1\n";
        return 0;
    }
    vl B;
    vl B2;

    for(int c1 = 0; c1 < n; c1++){
        if(A[c1] != A2[c1]){
            B.push_back(A[c1]);
            B2.push_back(A2[c1]);
            thing.push_back(c1+1);

        }
    }
    A.clear();
    A2.clear();


    n = sz(B);
    if(n == 0){
        cout << "0\n";
        return 0;
    }
    for(int c1 = 0; c1 < n; c1++){
        A.push_back(B[c1]);
        A2.push_back(B2[c1]);
    }
    d = 0;
    M.clear();
    for(int c1 = 0; c1 < n; c1++){
        if(M.find(A2[c1]) == M.end()){
            M[A2[c1]] = d;
            d++;
        }
    }

    for(int c1 = 0; c1 < n; c1++){
        A[c1] = M[A[c1]];
        A2[c1] = M[A2[c1]];
    }


    for(int c1 = 0; c1 < d; c1++){
        deg[c1] = 1;
        pek[c1] = c1;
    }

    ll comps = d;

    for(int c1 = 0; c1 < n; c1++){
        if(par(A[c1]) != par(A2[c1])){
            merg(A[c1],A2[c1]);
            comps--;
        }
    }

    ll leftovers = m-n;
    ll ans = 0;
    if(leftovers >= 3 && comps > 2){
        extramove.push_back(0);
        leftovers--;
        for(int c1 = 0; c1 < n; c1++){
            if(leftovers == 0)break;
            if(par(A[0]) != par(A[c1])){
                leftovers--;
                merg(A[0],A[c1]);
                extramove.push_back(c1);
            }
        }
        ll old = A[extramove[sz(extramove)-1]];
        for(int c1 = sz(extramove)-1; c1 >= 1; c1--){
            A[extramove[c1]] = A[extramove[c1-1]];
        }
        A[0] = old;
        ans++;
    }

    for(int c1 = 0; c1 < n; c1++){
        if(A[c1] != A2[c1]){
            C[A2[c1]+n].insert(c1);
            C[c1].insert(A[c1]+n);
            indeg[c1]++;
            outdeg[c1]++;
            indeg[A[c1]+n]++;
            outdeg[A2[c1]+n]++;
        }
    }


    for(int c1 = 0; c1 < n; c1++){
        if(indeg[c1] > 0){
            vl AA = eulertour(c1);
            vl BB;
            for(int c2 = 0; c2 < sz(AA); c2 += 2){
                BB.push_back(AA[c2]);
            }
            anses.push_back(BB);
        }
    }

    //cerr << "ext: " << sz(anses) << " comps: " << comps << "\n";

    cout << ans+sz(anses) << "\n";
    if(sz(extramove) > 0){
        cout << sz(extramove) << "\n";
        for(int c1 = 0; c1 < sz(extramove); c1++){
            cout << thing[extramove[c1]] << " ";
        }
        cout << "\n";
    }
    for(int c2 = 0; c2 < sz(anses); c2++){
        cout << sz(anses[c2]) << "\n";
        for(int c1 = 0; c1 < sz(anses[c2]); c1++){
            cout << thing[anses[c2][c1]] << " ";
        }
        cout << "\n";
    }


    return 0;
}