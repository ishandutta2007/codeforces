#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second
typedef long long ll;
using namespace std;

vector<int> a_b, b_a;
vpii ans;
int main(){
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	int cnt_s = count(s.begin(), s.end(), 'a');
	int cnt_t = count(t.begin(), t.end(), 'a');
	if((cnt_s + cnt_t) % 2){
		cout << -1;
		return 0;
	}
	for(int i=0;i<n;i++){
		if(s[i] == t[i]){
			continue;
		}
		if(s[i] == 'a'){
			a_b.push_back(i);
		}else{
			b_a.push_back(i);
		}
	}
	for(int i=0;i<a_b.size()/2;i++){
		ans.push_back({a_b[i*2], a_b[i*2+1]});
	}
	for(int i=0;i<b_a.size()/2;i++){
		ans.push_back({b_a[i*2], b_a[i*2+1]});
	}
	if(a_b.size() % 2){
		ans.push_back({a_b.back(), a_b.back()});
		ans.push_back({a_b.back(), b_a.back()});
	}
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();i++){
		cout << ans[i].fi + 1 << ' ' << ans[i].se + 1 << endl;
	}
	return 0;
}