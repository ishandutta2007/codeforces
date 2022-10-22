#include <bits/stdc++.h>
#define INF 2147483647
#define LLINF LLONG_MAX
#define PI 3.1415926535
#define MOD 1000000007
#define SP << " "
#define EL << "\n"
#define sqr(x) ((x)*(x))
//mt19937 x(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 x(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;

template <class T1, class T2>
ostream& operator << (ostream& out, pair<T1,T2> p) {
	return out << "(" << p.first << "," << p.second << ")";
}
template <template <class... args> class TContainer, class... T>
ostream& operator<<(ostream& out, TContainer<T...>& Container) {	
    out << "[";
    bool first = 1;
    for(auto x : Container) {
    	if (!first) cout << ",";
    	cout << x;
    	first = 0;
    }
    out << "]";
    return out;
}

static auto _batch_ios = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 42;
}();

/*
  _____                                               _               _       _                   _ _ 
 |  __ \                                             (_)             (_)     | |                 | | |
 | |__) | __ ___   __ _ _ __ __ _ _ __ ___  _ __ ___  _ _ __   __ _   _ ___  | |__   __ _ _ __ __| | |
 |  ___/ '__/ _ \ / _` | '__/ _` | '_ ` _ \| '_ ` _ \| | '_ \ / _` | | / __| | '_ \ / _` | '__/ _` | |
 | |   | | | (_) | (_| | | | (_| | | | | | | | | | | | | | | | (_| | | \__ \ | | | | (_| | | | (_| |_|
 |_|   |_|  \___/ \__, |_|  \__,_|_| |_| |_|_| |_| |_|_|_| |_|\__, | |_|___/ |_| |_|\__,_|_|  \__,_(_)
                   __/ |                                       __/ |                                  
                  |___/                                       |___/                                                                                 
*/

int cnt[2][200007];

int main() {
	int q;
	cin >> q;
	
	int x,f,tcnt;
	
	for (int i = 0; i < q; i++) {
		int n;
		cin >> n;
		
		for (int j = 1; j <= n; j++) {
			cnt[0][j] = 0;
			cnt[1][j] = 0;
		}
			
		for (int j = 0; j < n; j++) {
			cin >> x >> f;
			cnt[f][x]++;
		}
		
		vector<pair<int,int> > v;
		v.reserve(200007);
		
		for (int j = 1; j <= n; j++) {
			tcnt = cnt[0][j] + cnt[1][j];
			if (tcnt > 0)
				v.push_back({tcnt,cnt[1][j]});
		}
		
		sort(v.begin(),v.end());
		
		int ans = 0;
		int ans2 = 0;
		int cur = INF;
		
		multiset<int> s;
		int insertptr = v.size();
		
		for (int j = v.size()-1; j >= 0; j--) {
			cur = min(cur-1,v[j].first);
			if (cur <= 0)
				break;
			ans += cur;
			
			for (; insertptr > 0 && v[insertptr-1].first >= cur; insertptr--)
				s.insert(v[insertptr-1].second);
					
			ans2 += min(*s.rbegin(),cur);
			s.erase(--s.end());
		}
		
		cout << ans SP << ans2 EL;
	}
	
	return 0;
}