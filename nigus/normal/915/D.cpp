#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;

ll n,m,k,T,q;

vector<vi> C(501, vi());
vi A;
vi B;
int upd[501] = {0};
int indeg[501] = {0};
int indeg2[501] = {0};
int now = 0;

int PAR[501] = {0};

int in(int i){
    if(upd[i] == now){
        return indeg2[i];
    }
    else{
        return indeg[i];
    }
}

void dec(int i){
    if(upd[i] == now){
        indeg2[i]--;
    }
    else{
        indeg2[i] = indeg[i]-1;
        upd[i] = now;
    }
    return;
}

bool cyc(int a, int b){
    queue<int> Q;
    int ans = 0;
    for(int c1 = 0; c1 < n; c1++){
        if(in(c1) == 0){
            Q.push(c1);
            ans++;
        }
    }
    while(!Q.empty()){
        ll i = Q.front();
        Q.pop();
        for(int c1 = 0; c1 < sz(C[i]); c1++){
            int c = C[i][c1];
            if(a == i && c == b){continue;}
            dec(c);
            if(in(c) == 0){
                Q.push(c);
                ans++;
            }

        }
    }

    if(a == -1 && b == -1){

        for(ll c1 = 0; c1 < n; c1++){
            if(in(c1) > 0){
                for(ll c2 = 0; c2 < sz(C[c1]); c2++){
                    int c = C[c1][c2];


                    if(in(c) == 1){
                        A.push_back(c1);
                        B.push_back(c);
                    }
                }
            }
        }

    }

    return (ans == n);

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b,c,d;

    cin >> n >> m;
    for(int c1 = 0; c1 < m; c1++){
        cin >> a >> b;
        a--;
        b--;
        indeg[b]++;
        C[a].push_back(b);
    }
    now++;
    if(cyc(-1,-1)){
        cout << "YES\n";
    }
    else{

        bool yes = 0;
        for(ll c1 = 0; c1 < sz(A); c1++){
            now++;
            dec(B[c1]);
            if(cyc(A[c1],B[c1])){
                yes = 1;
            }
        }
        if(yes){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}