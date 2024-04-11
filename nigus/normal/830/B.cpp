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

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,T,k,q;
ll p;

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

vector<vector<ll> > C(100001, vector<ll>());

vector<ll> A;
vector<ll> A2;


ll next(ll i, ll x){
// not inclusive
if(C[x][0] > i)return C[x][0];
if(C[x][sz(C[x])-1] <= i)return C[x][0];

ll l = 0;
ll r = sz(C[x]) - 1;

while(l < r-1){

    ll mid = (l+r)/2;

    if(C[x][mid] > i){
        r = mid;
    }else{
        l = mid;
    }

}
return C[x][r];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;
    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
        A2.push_back(a);
        C[a].push_back(c1);
    }

    FT ft(n);
    sort(all(A2));


    ll now = 0;
    ll ans = 0;
    for(ll c1 = 0; c1 < n; c1++){

        if(c1 == 0 && A2[0] == A[0]){
            ans++;
            ft.update(0,1);
        }
        else{
            ll nex = next(now, A2[c1]);

            ll deads = 0;
            ll dist = 0;

            if(nex < now){
                deads = (ft.query(n) - ft.query(now)) + ft.query(nex);
                dist = (n-now) + (nex + 1);
            }
            else{

                deads = (ft.query(nex+1) - ft.query(now));
                dist = nex - now + 1;

            }

            ans += dist-deads;
            //cout << dist-deads << " " << now << "\n";
            ft.update(nex,1);
            now = nex;
        }
    }

    cout << ans << "\n";

    return 0;
}