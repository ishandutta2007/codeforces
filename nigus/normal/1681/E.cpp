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
 
const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;
 
const int MAXN = 100006;

struct pt{
    ll x,y;
};

ll dist(pt p1, pt p2){
    return abs(p1.x-p2.x) + abs(p1.y-p2.y);
}

vector<vector<pt>> doors;

ll to_next(int i, bool d1, bool d2){
    if(i >= n-1 || i < 0){
        // what?
        return 0;
    }

    pt out1 = doors[i][d1];
    if(d1 == 0)out1.x++;
    if(d1 == 1)out1.y++;
    ll res1 = 1 + dist(out1, doors[i+1][d2]);

    pt out2 = doors[i][(d1^1)];
    if(d1 == 0)out2.y++;
    if(d1 == 1)out2.x++;
    ll res2 = 1 + dist(doors[i][0], doors[i][1]) + dist(out2, doors[i+1][d2]);

    return min(res1, res2);
}

struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
    ll VAL[2][2] = {0};

	Node(int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
            rep(d1,0,2){
                rep(d2,0,2){
                    VAL[d1][d2] = big*big;
                    rep(d3,0,2){
                        rep(d4,0,2){
                            ll temp = (l->VAL[d1][d3]) + to_next(mid-1, d3, d4) + (r->VAL[d4][d2]);
                            VAL[d1][d2] = min(VAL[d1][d2], temp);
                        }
                    }
                }
            }
		}
		else{
            VAL[0][0] = 0;
            VAL[1][1] = 0;
            VAL[0][1] = dist(doors[lo][0], doors[lo][1]);
            VAL[1][0] = dist(doors[lo][0], doors[lo][1]);
        }
	}

    vl query2(int L, int R){
        if (R <= lo || hi <= L) return {0, 0, 0, 0};
		if (L <= lo && hi <= R) return {VAL[0][0], VAL[0][1], VAL[1][0], VAL[1][1]};

        int mid = lo + (hi - lo)/2;

        vl res = {big*big, big*big, big*big, big*big};
        
        vl lres = (l->query2(L, R));
        vl rres = (r->query2(L, R));

        if(R <= mid)return lres;
        if(L >= mid)return rres;

        //cerr << L <<  " " << R << "  dsa\n";

        rep(d1,0,2){
            rep(d2,0,2){
                rep(d3,0,2){
                    rep(d4,0,2){
                        ll temp = lres[d1*2+d3] + rres[d4*2+d2];

                        ll mid_term = to_next(mid-1, d3, d4);
                       // if(R <= mid || L >= mid)mid_term = 0;

                        //cerr << mid_term << "  rest: " << temp << " " << lo << " " << hi <<  "  dfhsk\n";

                        temp += mid_term;
                        
                        res[d1*2+d2] = min(res[d1*2+d2], temp);
                    }
                }
            }
        }

		return res;
    }

	ll query(int L, int R, int d1, int d2) {
		vl ans = query2(L, R);
        return ans[d1*2+d2];
	}

};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a,b,c,d,e;
    
    cin >> n;
    rep(c1,0,n-1){
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        vector<pt> door;
        door.push_back({a, b});
        door.push_back({c, d});
        doors.push_back(door);

        if(c1 == n-2){
            vector<pt> door2;
            door2.push_back({a+1, b});
            door2.push_back({c,d+1});
            doors.push_back(door2);
        }
    }

    

    cin >> m;

    Node segtree(0, n);
    rep(c1,0,m){
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;

        if(max(a, b) > max(c, d)){
            swap(a,c);
            swap(b,d);
        }
        int layer1 = max(a, b);
        int layer2 = max(c, d);

        //cerr << layer1 << " " << layer2 << "  layers\n";

        if(layer1 == layer2){
            cout << dist({a, b}, {c, d}) << "\n";
        }
        else{
            ll res = big*big;
            rep(d1,0,2){
                rep(d2,0,2){

                    pt out2 = doors[layer2-1][d2];
                    if(d2 == 0)out2.x++;
                    if(d2 == 1)out2.y++;

                    ll temp = dist(doors[layer1][d1], {a, b}) + 1 + dist(out2, {c, d});
                    ll seg = segtree.query(layer1, layer2, d1, d2);
                 //   cerr << "seg: " << seg << "   rest: " << temp << "\n";
                    temp += seg;
                    res = min(res, temp);
                }
            }
            cout << res << "\n";
        }


    }

    return 0;
}