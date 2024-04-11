#include <bits/stdc++.h>
using namespace std;
#define int ll
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pi> vp;
typedef vector<pl> vpl;
 
struct t{
	int x;
	int i;
};
 
bool cmp(t a, t b){
	return (a.x < b.x);
}
 
void no(){
	cout << "-1\n";
	exit(0);
}
 
signed main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr); 
	cerr.tie(nullptr);	
 
	int n;
	cin >> n;
 
	vector<t> a(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i].x;
		a[i].i = i + 1;
	}
 
	sort(a.begin() + 1, a.end(), cmp);
	reverse(a.begin() + 1, a.end());
 
	int r = 0;
	vp sol;
	for (int i = 0; i < n; ++i){
		if (i > r){
			no();
		}
 
		if (r >= n - 1) break;
 
		for (int j = 0; j < a[i].x; ++j){
 
			if (r >= n - 1) break;
 
			sol.push_back({a[i].i, a[++r].i});
		}
	}
 
	cout << (int)sol.size() << '\n';
	for (auto& i : sol)
		cout << i.first << ' ' << i.second << '\n';
}