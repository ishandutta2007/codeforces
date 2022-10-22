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

const ll big = 1000000007;
const ll mod = 998244353;

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1)
			s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1)
			res += s[pos-1];
		return res;
	}
};

int n,m,k,q,p;
ll T;

vi A;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b,c,e;

    scanf("%d", &n);

    FT ft(n);
    ll inv = 0;
    for(int c1 = 0; c1 < n; c1++){
        scanf("%d", &a);

        inv += ft.query(n-a);
        ft.update(n-a,1);
    }

    inv += n;
    inv %= 2;

    if(inv == 1){
        printf("Um_nik\n");
    }
    else{
        printf("Petr\n");
    }

    return 0;
}