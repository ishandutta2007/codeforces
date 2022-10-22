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

ll n,m,T,k,d;
const ll big = 1000000007;


vi match2;

vector<int> match;
vector<bool> seen;
template<class G>
bool find(int j, G &g) {
	if (match[j] == -1) return 1;
	seen[j] = 1; int di = match[j];
	trav(e, g[di])
		if (!seen[e] && find(e, g)) {
			match[e] = di;
			match[j] = -1;
			return 1;
		}
	return 0;
}
template<class G>
int dfs_matching(G &g, int n, int m) {
	match.assign(m, -1);
	match2.assign(n, -1);
	rep(i,0,n) {
		seen.assign(m, false);
		trav(j,g[i])
			if (find(j, g)) {
				match[j] = i;
				break;
			}
	}

	for(int c1 = 0; c1 < m; c1++){
        if(match[c1] != -1){
            match2[match[c1]] = c1;
        }
	}

	return m - count(all(match), -1);
}

vector<vi> C(4001,vi());

struct seg{
    ll x1,y1,x2,y2;
};

vl X;
vl Y;
vl ind1;
vl ind2;

void pseg(seg s){
    cout << s.x1 << " " << s.y1 << " " << s.x2 << " " << s.y2 << "\n";
    return;
}

bool comp1(ll i, ll j){
    if(X[i] == X[j]){return Y[i] < Y[j];}
    else{return X[i] < X[j];}
}

bool comp2(ll i, ll j){
    if(Y[i] == Y[j]){return X[i] < X[j];}
    else{return Y[i] < Y[j];}
}

bool taken1[1001] = {0};
bool taken2[1001] = {0};

bool yxok(ll i1, ll i2, ll j1, ll j2){

 //   if(!taken[j1])return 1;

    ll a1 = ind2[i1];
    ll a2 = ind2[i2];

    ll b1 = ind1[j1];
    ll b2 = ind1[j2];

    if(Y[a1] != Y[a2])return 0;
    if(X[b1] != X[b2])return 1;

    if(X[b1] >= max(X[a1],X[a2]) || X[b1] <= min(X[a1],X[a2]))return 1;
    if(Y[a1] >= max(Y[b1],Y[b2]) || Y[a1] <= min(Y[b1],Y[b2]))return 1;
    return 0;
}

vector<vi> C2(4001, vi());

bool mark1[1001] = {0};
bool mark2[1001] = {0};

bool TT[4001] = {0};
bool vis[4001] = {0};

vector<seg> vseg;
vector<seg> hseg;

void dfs(ll i){
    TT[i] = 1;
    for(int c1 = 0; c1 < sz(C2[i]); c1++){
        ll a = C2[i][c1];
        if(!TT[a]){
            dfs(a);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n;
    //n = 1000;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a >> b;
      //  a = rand()%400;
      //  b = rand()%400;
        X.push_back(a);
        Y.push_back(b);
        ind1.push_back(c1);
        ind2.push_back(c1);
    }

    sort(all(ind1),comp1);
    sort(all(ind2),comp2);


    for(int c1 = 0; c1 < n-1; c1++){
        for(int c2 = 0; c2 < n-1; c2++){

            if(Y[ind2[c1]] != Y[ind2[c1+1]] || X[ind1[c2]] != X[ind1[c2+1]])continue;

            if(!yxok(c1,c1+1,c2,c2+1)){
                C[c2].push_back(c1);
            }

        }

    }
    dfs_matching(C,n-1,n-1);

    vi start;

    for(int c1 = 0; c1 < n-1; c1++){
        if(match2[c1] == -1){
            start.push_back(c1);
        }

        for(int c2 = 0; c2 < sz(C[c1]); c2++){
            a = C[c1][c2];
            if(match2[c1] == a){
                C2[a+n].push_back(c1);
            }
            else{
                C2[c1].push_back(a+n);
            }

        }

    }

    for(int c1 = 0; c1 < sz(start); c1++){
        dfs(start[c1]);
    }

    for(int c1 = 0; c1 < n-1; c1++){

        if(TT[c1])taken1[c1] = 1;
        if(!TT[n+c1])taken2[c1] = 1;
    }



    for(int c1 = 0; c1 < n; c1++){
        a = ind1[c1];
        if(mark1[a])continue;

        ll x = X[a];
        ll y1 = Y[a];
        ll y2 = Y[a];
        for(int c2 = c1; c2 < n; c2++){
            b = ind1[c2];
            if(X[b] != x)break;
            if(c2 > c1 && !taken1[c2-1])break;

            mark1[b] = 1;
            y2 = Y[b];
        }

        vseg.push_back({x,y1,x,y2});

    }

    for(int c1 = 0; c1 < n; c1++){
        a = ind2[c1];
        if(mark2[a])continue;

        ll y = Y[a];
        ll x1 = X[a];
        ll x2 = X[a];
        for(int c2 = c1; c2 < n; c2++){
            b = ind2[c2];
            if(Y[b] != y)break;
            if(c2 > c1 && !taken2[c2-1])break;

            mark2[b] = 1;
            x2 = X[b];
        }

        hseg.push_back({x1,y,x2,y});

    }

    cout << sz(hseg) << "\n";
    for(int c1 = 0; c1 < sz(hseg); c1++){
        pseg(hseg[c1]);
    }
    cout << sz(vseg) << "\n";
    for(int c1 = 0; c1 < sz(vseg); c1++){
        pseg(vseg[c1]);
    }

    return 0;
}