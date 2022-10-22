#pragma GCC optimize("O3")   //
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef unsigned long long ull;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);

ll random2(){
    return (1ll << 31ll)*eng()+eng();
}

ll n,m,k,q,T;

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 500001;

ll TWO[MAXN] = {0};

vector<vi> C(MAXN, vi());
vector<vi> CI(MAXN, vi());

vi A,B,I;

bool special[MAXN] = {0};

bool in_ans[MAXN] = {0};
vi ANS;

priority_queue<pll> units;

void unit(int i, int from){
    if(special[i] || in_ans[from])return;
    ANS.push_back(from);
    in_ans[from] = 1;
    special[i] = 1;
    rep(c1,0,sz(C[i])){
        //cerr << "JHKL";
        int j = C[i][c1];
        int f2 = CI[i][c1];
        if(!in_ans[f2])units.push({-f2, j});
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    ll t = 1;
    rep(c1,0,MAXN){
        TWO[c1] = t;
        t *= 2;
        t %= big;
    }

    cin >> q >> n;

    rep(c1,0,q){
        cin >> a;
        //a = rand()%2;
        if(a == 1){
            cin >> b;

            //b = random2()%n+1;


            b--;
            units.push({-c1, b});
        }
        else{
            cin >> b >> c;
          //  b = random2()%n+1;
            //c = random2()%n+1;


            b--;
            c--;
            A.push_back(b);
            B.push_back(c);
            I.push_back(c1);
            C[b].push_back(c);
            C[c].push_back(b);
            CI[b].push_back(c1);
            CI[c].push_back(c1);
        }
    }

    UF uf(n);

    while(!units.empty()){
        pll p = units.top();
        units.pop();
        unit(p.second, -p.first);
    }

    rep(c1,0,sz(I)){
        int i = I[c1];
        a = A[c1];
        b = B[c1];
       /* if((special[a]^special[b]) != 0){
            cerr << "HUH? " << c1 << "\n";
        }*/
        if(!special[a] && !special[b] && in_ans[i] == 0){
            if(uf.find(a) != uf.find(b)){
                in_ans[i] = 1;
                ANS.push_back(i);
                uf.join(a, b);
            }
        }
    }

    cout << TWO[sz(ANS)] << " " << sz(ANS) << "\n";
    sort(all(ANS));
    rep(c1,0,sz(ANS)){
        cout << ANS[c1]+1 << " ";
    }
    cout << "\n";

    return 0;
}