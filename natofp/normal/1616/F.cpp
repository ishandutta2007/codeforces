#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

const int mod = 3;

ll pow(ll base, ll p, ll MOD)
{
	if(p == 0) return 1;
	if(p % 2 == 0) { ll d = pow(base, p / 2, MOD); return (d * d) % MOD; }
	return (pow(base, p - 1, MOD) * base) % MOD;
}

ll inv(ll x, ll MOD) { return pow(x, MOD - 2, MOD); }

// If MOD equals 2, it becomes XOR operation and we can use vector of bitsets to build equation
// Complexity becomes 1/32

vector<ll> gauss(vector<vector<ll> > &a, ll MOD)
{
	int n = a.size(), m = a[0].size() - 1;

	for(int i = 0; i < n; i++)
		for(int j = 0; j <= m; j++)
			a[i][j] = (a[i][j] % MOD + MOD) % MOD;

	vector<int> where(m, -1);
	for(int col = 0, row = 0; col < m && row < n; col++)
	{
		int sel = row;
		for(int i = row; i < n; i++)
			if(a[i][col] > a[sel][col])
				sel = i;

			if(a[sel][col] == 0) { where[col] = -1; continue;
	}

        for(int i = col; i <= m; i++)
			swap(a[sel][i], a[row][i]);
		where[col] = row;

		ll c_inv = inv(a[row][col], MOD);
		for(int i = 0; i < n; i++)
			if(i != row)
			{
				if(a[i][col] == 0) continue;
			    	ll c = (a[i][col] * c_inv) % MOD;
			    	for(int j = 0; j <= m; j++)
				    a[i][j] = (a[i][j] - c * a[row][j] % MOD + MOD) % MOD;
			}

		row++;
    }
    vector<ll> ans(m, 0);
    ll result = 1;
    // for counting rank, take the count of where[i]==-1
    for(int i = 0; i < m; i++)
        if(where[i] != -1) ans[i] = (a[where[i]][m] * inv(a[where[i]][i], MOD)) % MOD;
		else result = (result * MOD) % mod;
	// This is validity check probably.May not be needed
    for(int i = 0; i < n; i++)
	{
		ll sum = a[i][m] % MOD;
		for(int j = 0; j < m; j++)
			sum = (sum + MOD - (ans[j] * a[i][j]) % MOD) % MOD;

		if(sum != 0) return {};
	}

	return ans;
}

int n, m;
vector<pair<pii, int> > edges;
const int nax = 105;
pii s[nax][nax];

void solve(){
    cin >> n >> m;
    for(int i=0;i<nax;i++){
        for(int j=0;j<nax;j++) s[i][j] = mp(-2, 0);
    }
    edges.clear();
    for(int i=1;i<=m;i++){
        int x, y, z; cin >> x >> y >> z;
        if(z == 3) z = 0;
        s[x][y] = s[y][x] = mp(z, i - 1);
        edges.pb(mp(mp(x, y), z));
    }

    vector<vector<ll> > matrix;

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(s[i][j].st != -2 && s[j][k].st != -2 && s[i][k].st != -2){
                    vector<int> ids = {s[i][j].nd, s[j][k].nd, s[i][k].nd};
                    vector<int> cols = {s[i][j].st, s[j][k].st, s[i][k].st};
                    //for(int c=0;c<3;c++){
                    //    cout << "WA" << ids[c] << " " << cols[c] << endl;
                    //}
                    int sum = 66;
                    for(int x : cols){
                        if(x != -1) sum -= x;
                    }
                    sum %= 3;
                    vector<ll> eq(m + 1);
                    eq[m] = sum;
                    //cout << "XD" << m << " " << sum << endl;
                    for(int c=0;c<3;c++){
                        if(cols[c] == -1) eq[ids[c]] = 1;
                    }
                    matrix.pb(eq);
                }
            }
        }
    }
    if(matrix.empty()){
        for(int i=0;i<m;i++){
            auto cur = edges[i].nd;
            if(cur == -1 || cur == 0) cur = 3;
            cout << cur << " ";
            assert(cur >= 1 && cur <= 3);
        }
        cout << "\n";
        return;
    }
    auto res = gauss(matrix, 3);
    if(res.empty()){
        cout << -1 << "\n";
    }
    else{
        for(int i=0;i<m;i++){
            auto cur = edges[i].nd;
            if(cur == -1){
                cur = res[i];
            }
            if(cur == 0) cur = 3;
            cout << cur << " ";
            assert(cur >= 1 && cur <= 3);
        }
        cout << "\n";
    }


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}