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

ll mod(ll i){
    if(i < 0)return mod(big-mod(-i));
    return i%big;
}

ll upp(ll i, ll j){
    if(j == 0)return 1;
    ll h = upp(i,j/2);
    if(j%2 == 0)return mod(h*h);
    return mod(mod(h*h)*i);
}


ll det(vector<vector<ll>>& a) {
	int n = sz(a); ll ans = 1;
	rep(i,0,n) {
		rep(j,i+1,n) {
			while (a[j][i] != 0) { // gcd step
				ll t = a[i][i] / a[j][i];
				if (t) rep(k,i,n)
					a[i][k] = (a[i][k] - a[j][k] * t) % big;
				swap(a[i], a[j]);
				ans *= -1;
			}
		}
		ans = ans * a[i][i] % big;
		if (!ans) return 0;
	}
	return (ans + big) % big;
}


int solveLinear(vector<vl>& A, vl& b, vl& x) {
	int n = sz(A), m = sz(x), ran = 0, br, bc;
	if (n) assert(sz(A[0]) == m);
	vi col(m); iota(all(col), 0);

	rep(i,0,n) {
		ll v, bv = 0;
		rep(r,i,n) rep(c,i,m)
			if ((v = abs(A[r][c])) > bv)
				br = r, bc = c, bv = v;
		if (bv == 0) {
			rep(j,i,n) if (b[j] != 0) return -1;
			break;
		}
		swap(A[i], A[br]);
		swap(b[i], b[br]);
		swap(col[i], col[bc]);
		rep(j,0,n) swap(A[j][i], A[j][bc]);
		bv = upp(A[i][i],big-2);
		rep(j,i+1,n) {
			ll fac = mod(A[j][i] * bv);
			b[j] -= fac * b[i];
			b[j] = mod(b[j]);
			rep(k,i+1,m) {A[j][k] -= fac*A[i][k];A[j][k] = mod(A[j][k]);}
		}
		ran++;
	}

	x.assign(m, 0);
	for (int i = ran; i--;) {
		b[i] *= upp(A[i][i],big-2);
		b[i] = mod(b[i]);
		x[col[i]] = b[i];
		rep(j,0,i){ b[j] -= A[j][i] * b[i];b[j] = mod(b[j]);}
	}
	return ran; // (multiple solutions if rank < m)
}


ll n,m,k,T;

vector<vector<ll> > C(101 ,vector<ll>());
vector<vector<ll> > D;
bool M[101][101] = {0};

int main() {

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n;
    for(ll c1 = 0; c1 < n-1; c1++){
        cin >> a >> b;
        a--;
        b--;
        //a = 0;
        //b = c1+1;
        C[a].push_back(b);
        C[b].push_back(a);
        M[a][b] = 1;
        M[b][a] = 1;
    }

    ll t = 1;
    while(t <= n)t *= 2;

    vl x(n);

    for(ll c1 = 0; c1 < n; c1++){

        D.clear();
        for(ll c2 = 1; c2 < n; c2++){
            vector<ll> temp;
            for(ll c3 = 1; c3 < n; c3++){
                if(c2 == c3)temp.push_back(mod((n-1 - sz(C[c2])) + (sz(C[c2])) * c1));
                if(c2 != c3){

                    if(M[c2][c3] == 0){
                        temp.push_back(mod(-1));
                    }
                    else{
                        temp.push_back(mod(-c1));
                    }
                }
            }
            D.push_back(temp);
        }

        x[c1] = det(D);
    }


    vector<vl> AA;
    for(ll c1 = 0; c1 < n; c1++){
        vector<ll> temp;
        ll t2 = 1;
        for(ll c2 = 0; c2 < n; c2++){
            temp.push_back(t2);
            t2 = mod(t2*c1);
        }
        AA.push_back(temp);
    }

    vl y(n);
    solveLinear(AA,x,y);

    for(ll c1 = 0; c1 < n; c1++){
        cout << y[c1] << " ";
    }




    return 0;
}