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

int n,m,k,T,q;

vector<vi> C(1000000, vi());
int pek[1000001] = {0};
int deg[1000001] = {0};
vi A;
vi ind;

bool mark[1000001] = {0};

bool comp(int i, int j){
    return A[i] < A[j];
}

int par(int i){
    int i2 = i;
    while(pek[i2] != i2)i2 = pek[i2];
    return i2;
}

void merg(int i, int j){
    int i2 = par(i);
    int j2 = par(j);
    if(i2 != j2){
        if(deg[j2] > deg[i2]){
            int temp= i2;
            i2 = j2;
            j2 = temp;
        }
        deg[i2] += deg[j2];
        pek[j2] = i2;
    }
    return;
}

int main() {

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b,c,d;

    scanf("%d",&n);
    for(int c1 = 0; c1 < n; c1++){
        scanf("%d",&a);
        A.push_back(a);
        ind.push_back(c1);
        pek[c1] = c1;
        deg[c1] = 1;
    }
    for(int c1 = 0; c1 < n-1; c1++){
        scanf("%d",&a);
        scanf("%d",&b);
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    sort(all(ind),comp);
    ll ans = 0;

    for(int c1 = 0; c1 < n; c1++){
        int a = ind[c1];
        ll sum = 0;
        ll sqsum = 0;
        for(int c2 = 0; c2 < sz(C[a]); c2++){
            int b = C[a][c2];
            if(mark[b]){
                sum += deg[par(b)];
                sqsum += ll(deg[par(b)]) * ll(deg[par(b)]);

                merg(a,b);
            }
        }

       // cout << a+1 << " " << A[a] << "   " << ((sum*sum-sqsum)/2 + sum) << " " << sum << "\n";

        ans += ((sum*sum-sqsum)/2 + sum) * A[a];
        mark[a] = 1;
    }


    for(ll c1 = 0; c1 < n; c1++){
        mark[c1] = 0;
        deg[c1] = 1;
        pek[c1] = c1;
    }
    reverse(all(ind));
    ll ans2 = 0;

    for(int c1 = 0; c1 < n; c1++){
        int a = ind[c1];
        ll sum = 0;
        ll sqsum = 0;
        for(int c2 = 0; c2 < sz(C[a]); c2++){
            int b = C[a][c2];
            if(mark[b]){
                sum += deg[par(b)];
                sqsum += ll(deg[par(b)]) * ll(deg[par(b)]);
                merg(a,b);
            }
        }
        ans2 += ((sum*sum-sqsum)/2 + sum) * A[a];
        mark[a] = 1;
    }

    cout << ans-ans2 << "\n";


    return 0;
}