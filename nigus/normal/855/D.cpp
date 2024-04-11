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

const ll big = 1000000007ll;
const ll big2 = 1000000009ll;
ll n,m,k,q,w,h,x;

struct Tree{
    vector<vector<int> > C;
    vector<vector<int> > CW;
    vector<int> line;
    vector<int> labels;
    vector<int> invlabels;
    vector<int> depth;
    vector<int> FL;
    vector<vector<int> > ST;
    int d = 0;

    void dfs(int i, int par){
        if(labels[i] == -1){
            labels[i] = d;
            invlabels.push_back(i);
            FL[i] = line.size();
            d++;
        }
        int l = labels[i];
        line.push_back(l);
        for(int c1 = 0; c1 < C[i].size(); c1++){
            int j = C[i][c1];
            if(j != par){
                depth[j] = depth[i] + CW[i][c1];
                dfs(j,i);
                line.push_back(l);
            }
        }
    }

    int lca(int i, int j){
        int a = min(FL[i],FL[j]);
        int b = max(FL[i],FL[j]);
        int dep = 31 - __builtin_clz(b+1-a);
        int l = min(ST[dep][a] , ST[dep][b + 1 - (1 << dep)]);
        return invlabels[l];
    }

    int dist(int i, int j){
        return depth[i]+depth[j]-2*depth[lca(i,j)];
    }

    void setup(){
        for(int c1 = 0; c1 < C.size(); c1++){
            labels.push_back(-1);
            depth.push_back(0);
            FL.push_back(0);
        }
        dfs(0,-1);
        int t = 1;
        int p = 1;
        while(t < line.size()){
            t *= 2;
            p++;
        }
        for(int c1 = 0; c1 < p; c1++){
            vector<int> V;
            ST.push_back(V);
        }
        int N = line.size();
        for(int c1 = 0; c1 < p; c1++){
            for(int c2 = 0; c2 < N; c2++){
                if(c1 == 0){
                    ST[c1].push_back(line[c2]);
                }
                else{
                    ST[c1].push_back(min(ST[c1-1][c2] , ST[c1-1][min(N-1 , c2 + (1 << (c1-1)))]));
                }
            }
        }
    }
};


vector<ll> tt;
vector<Tree> t;
vector<ll> cn;

vector<ll> ts;

vector<vector<ll> > D(100001, vector<ll>());

void dfs(ll i, ll par, ll j){
    for(ll c1 = 0; c1 < sz(t[j].C[i]); c1++){
        ll a = t[j].C[i][c1];
        if(a != par){
            D[j][a] = D[j][i]+1;
            dfs(a,i,j);
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;
    cin >> n;
    vector<ll> rts;

    ll now = 0;
    vector<ll> A;
    vector<ll> W;

    for(ll c1 = 0; c1 < n; c1++){
        cin >> a >> b;
        a--;
        A.push_back(a);
        W.push_back(b);
        if(a != -2){
            ll j = tt[a];
            cn.push_back(ts[j]);
            ts[j]++;
            tt.push_back(j);
        }
        else{
            tt.push_back(now);
            ts.push_back(1);
            cn.push_back(0);
            now++;
            rts.push_back(c1);
        }
    }


    for(ll c1 = 0; c1 < now; c1++){
        Tree t2;
        for(int c2 = 0; c2 < ts[c1]; c2++){
            D[c1].push_back(0);
            vector<int> V1;
            vector<int> V2;
            t2.C.push_back(V1);
            t2.CW.push_back(V2);
        }
        t.push_back(t2);
    }


    for(ll c1 = 0; c1 < n; c1++){

        if(A[c1] != -2){

            ll j = tt[c1];
            t[j].C[cn[c1]].push_back(cn[A[c1]]);
            t[j].C[cn[A[c1]]].push_back(cn[c1]);
            t[j].CW[cn[c1]].push_back(W[c1]);
            t[j].CW[cn[A[c1]]].push_back(W[c1]);
        }

    }

    cin >> q;
    for(ll c1 = 0; c1 < now; c1++){
        t[c1].setup();
        dfs(0,-1,c1);
    }
    for(ll c1 = 0; c1 < q; c1++){
        cin >> c >> a >> b;
        a--;
        b--;
        ll j = tt[a];
        if(c == 1){

            if(tt[a] != tt[b] || a == b){
                cout << "NO\n";
                continue;
            }


            a = cn[a];
            b = cn[b];
            if(t[j].lca(a,b) == a && t[j].dist(a,b) == 0){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
        else{

            //cout << D[a] << "  " << D[b] << "\n";

            if(tt[a] != tt[b] || a == b){
                cout << "NO\n";
                continue;
            }

            a = cn[a];
            b = cn[b];
            if(t[j].lca(a,b) == a && t[j].dist(a,b) == D[j][b]-D[j][a]){
                cout << "YES\n";
            }
            else{
                ll l = t[j].lca(a,b);

                //cout << D[a] << "  " << D[b] << "\n";

                if(t[j].dist(a,l) == 0 && t[j].dist(b,l) == D[j][b]-D[j][l] && l != b){
                    cout << "YES\n";
                }
                else{
                    cout << "NO\n";
                }
            }

        }
    }


    return 0;
}