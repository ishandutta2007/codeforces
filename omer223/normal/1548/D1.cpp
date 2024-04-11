#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

ll b[4][4];
vector<pii> o{{0,0},{0,2},{2,0},{2,2}};

ll c3(ll x){
    return (x*(x-1)*(x-2))/6;
}

ll c2(ll x){
    return (x*(x-1))/2;
}

int main() {
	fast;
	int n;
	cin>>n;
	while(n--){
	    int x,y;
	    cin>>x>>y;
	    b[x%4][y%4]++;
	}
	ll ans = 0;
	for (auto i : o)ans += c3(b[i.ff][i.ss]);
	for (auto i : o){
	    for (auto j : o){
	        if(i!=j)ans+=(c2(b[i.ff][i.ss])*b[j.ff][j.ss]);
	    }
	}
	cout<<ans;
	return 0;
}