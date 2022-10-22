#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

long long n, k, arr[200005], c[200005], ans, tot = 0;

vector<long long> v[200005];

multiset<long long> s;

multiset<long long>::iterator it2, it3;

multiset<pll> ms;

multiset<pll>::iterator it, it1;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>  n >> k;
	for (int i=1; i<=n; i++){
		cin >> arr[i];
		s.insert(arr[i]);
	}
	for (int i=1; i<=k; i++){
		cin >> c[i];
		ms.insert(mp(c[i], -i));
	}
	long long cur = 0;
	while (tot < n){
		it = ms.lower_bound(mp(cur + 1, -1e9));
		long long x = (*it).second;
		if (it == ms.begin()){
			it2 = s.end();
			it2--;
			v[ans].push_back(*it2);
			s.erase(it2);
		}
		else{
			long long y = -(*it).second;
			it2 = s.lower_bound(y+1);
			if (it2 == s.begin()){
				ans++;
				cur = -1;
				tot--;
			}
			else {
				it2--;
				v[ans].push_back(*it2);
				s.erase(it2);
			}
		}
		tot++;
		cur++;
	}
	cout << ans + 1 << "\n";
	for (int i=0; i<=ans; i++){
		cout << v[i].size() << " ";
		for (int j=0; j<v[i].size(); j++){
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}