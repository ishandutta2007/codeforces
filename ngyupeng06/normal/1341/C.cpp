#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

long long n, m, t;
long long arr[200005], pos[200005];
set<pair<long long, long long> > s;
set<long long> s1[200005];
multiset<long long> ms;
multiset<long long>::iterator it2;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		set<pll>::iterator it, it1;
		long long cmax = 1;
		for (int i=1; i<=n; i++){
			cin >> arr[i];
			pos[arr[i]] = i;
			s.insert(mp(i,1));
			s1[1].insert(i);
			ms.insert(1);
		}
		bool gd = true;
		for (int i=1; i<=n; i++){
			long long x = pos[i];
			it2 = ms.end();
			it2--;
			cmax = *it2;
			if (s1[cmax].find(x) != s1[cmax].end()){
				s1[cmax].erase(x);
				it = s.lower_bound(mp(x,0));
				long long y = (*it).second;
				it1 = it;
				it++;
				s.erase(it1);
				ms.erase(ms.find(y));
				if (it!=s.end()){
					pll p = (*it);
					s.erase(it);
					ms.erase(ms.find(p.second));
					s1[p.second].erase(p.first);
					s.insert(mp(p.first, p.second + y));
					ms.insert(p.second + y);
					s1[p.second + y].insert(p.first);
				}
			}
			else {
				gd = false;
				break;
			}
		}
		if (gd) cout << "Yes\n";
		else cout << "No\n";
		s.clear();
		ms.clear();
		for (int i=1; i<=n; i++) s1[i].clear();
	}
}