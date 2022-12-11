#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

typedef pair<int, string> pst;

int main(){
	fastIO;
	int n;
	cin >> n;
	pst a[n];
	for(int i = 0;i < n;i ++ ){
		cin >> a[i].se >> a[i].fi;
	}
	sort(a, a + n);
	vector<pst> ans;
	int hi = 4000;
	for(int i = 0; i < n; i ++ ){
		if(a[i].fi > i){
			cout << "-1\n";
			return 0;
		}
		else{
			if(i == 0 or a[i].fi != a[i - 1].fi)
				hi -= 1;
			for(int j = 0;j <= ans.size(); j ++){
				if(a[i].fi == j){
					ans.insert(ans.begin() + j, mp(hi, a[i].se));
					break;
				}
			}
		}
	}
	for(auto x : ans)
		cout << x.se << " " << x.fi << "\n";
	return 0;
}