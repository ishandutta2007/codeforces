#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

vector<string> res = {

"f(-40) = -319993.68",
"f(-41) = -344598.60",
"f(-42) = -370433.52",
"f(-43) = -397528.44",
"f(-44) = -425913.37",
"f(-45) = -455618.29",
"f(-46) = -486673.22",
"f(-47) = -519108.14",
"f(-48) = -552953.07",
"f(-49) = -588238.00",
"f(-50) = -624992.93",
"",
"f(-30) = -134994.52",
"f(-31) = -148949.43",
"f(-32) = -163834.34",
"f(-33) = -179679.26",
"f(-34) = -196514.17",
"f(-35) = -214369.08",
"f(-36) = -233274.00",
"f(-37) = -253258.92",
"f(-38) = -274353.84",
"f(-39) = -296588.76",
"f(-40) = -319993.68",
"",
"f(-20) = -39995.53",
"f(-21) = -46300.42",
"f(-22) = -53235.31",
"f(-23) = -60830.20",
"f(-24) = -69115.10",
"f(-25) = -78120.00",
"f(-26) = -87874.90",
"f(-27) = -98409.80",
"f(-28) = -109754.71",
"f(-29) = -121939.61",
"f(-30) = -134994.52",
"",
"f(-10) = -4996.84",
"f(-11) = -6651.68",
"f(-12) = -8636.54",
"f(-13) = -10981.39",
"f(-14) = -13716.26",
"f(-15) = -16871.13",
"f(-16) = -20476.00",
"f(-17) = -24560.88",
"f(-18) = -29155.76",
"f(-19) = -34290.64",
"f(-20) = -39995.53",
"",
"f(0) = 0.00",
"f(-1) = -4.00",
"f(-2) = -38.59",
"f(-3) = -133.27",
"f(-4) = -318.00",
"f(-5) = -622.76",
"f(-6) = -1077.55",
"f(-7) = -1712.35",
"f(-8) = -2557.17",
"f(-9) = -3642.00",
"f(-10) = -4996.84",
"",
"f(10) = MAGNA NIMIS!",
"f(9) = MAGNA NIMIS!",
"f(8) = MAGNA NIMIS!",
"f(7) = MAGNA NIMIS!",
"f(6) = MAGNA NIMIS!",
"f(5) = MAGNA NIMIS!",
"f(4) = 322.00",
"f(3) = 136.73",
"f(2) = 41.41",
"f(1) = 6.00",
"f(0) = 0.00",
"",
"f(20) = MAGNA NIMIS!",
"f(19) = MAGNA NIMIS!",
"f(18) = MAGNA NIMIS!",
"f(17) = MAGNA NIMIS!",
"f(16) = MAGNA NIMIS!",
"f(15) = MAGNA NIMIS!",
"f(14) = MAGNA NIMIS!",
"f(13) = MAGNA NIMIS!",
"f(12) = MAGNA NIMIS!",
"f(11) = MAGNA NIMIS!",
"f(10) = MAGNA NIMIS!",
"",
"f(30) = MAGNA NIMIS!",
"f(29) = MAGNA NIMIS!",
"f(28) = MAGNA NIMIS!",
"f(27) = MAGNA NIMIS!",
"f(26) = MAGNA NIMIS!",
"f(25) = MAGNA NIMIS!",
"f(24) = MAGNA NIMIS!",
"f(23) = MAGNA NIMIS!",
"f(22) = MAGNA NIMIS!",
"f(21) = MAGNA NIMIS!",
"f(20) = MAGNA NIMIS!",
"",
"f(40) = MAGNA NIMIS!",
"f(39) = MAGNA NIMIS!",
"f(38) = MAGNA NIMIS!",
"f(37) = MAGNA NIMIS!",
"f(36) = MAGNA NIMIS!",
"f(35) = MAGNA NIMIS!",
"f(34) = MAGNA NIMIS!",
"f(33) = MAGNA NIMIS!",
"f(32) = MAGNA NIMIS!",
"f(31) = MAGNA NIMIS!",
"f(30) = MAGNA NIMIS!",
"",
"f(50) = MAGNA NIMIS!",
"f(49) = MAGNA NIMIS!",
"f(48) = MAGNA NIMIS!",
"f(47) = MAGNA NIMIS!",
"f(46) = MAGNA NIMIS!",
"f(45) = MAGNA NIMIS!",
"f(44) = MAGNA NIMIS!",
"f(43) = MAGNA NIMIS!",
"f(42) = MAGNA NIMIS!",
"f(41) = MAGNA NIMIS!",
"f(40) = MAGNA NIMIS!",
""};

string str(ll x) {
	if (x == 0) return "0";
	if (x < 0) return "-" + str(-x);
	if (x < 10) return string(1,'0'+x);
	return string(1,'0'+x/10) + string(1,'0'+x%10);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n = 11;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	reverse(all(a));
	
	for (ll x: a) {
		string pref = "f(" + str(x) + ")";
		
		for (string ans: res) if (ans.substr(0,sz(pref)) == pref) {
			cout << ans << endl;
			break;
		}
	}





}