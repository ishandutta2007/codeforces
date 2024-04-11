#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

int n, m, k, t, a, b, c, d;
int p[1005], sz[1005];

int findSet(int id) { 
	return (p[id] == id) ? id : (p[id] = findSet(p[id])); 
} 
bool sameset(int a, int b) { 
	return findSet(a) == findSet(b); 
} 
void mergeset(int a, int b) { 
	int pa = findSet(a), pb = findSet(b); 
	sz[pb] += sz[pa];
	p[pa] = pb; 
}

multiset<int> s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> d;
	for (int i=1; i<=n; i++){
		p[i] = i;
		sz[i] = 1;
		s.insert(1);
	}
	ll cnt = 0;
	for (int i=0; i<d; i++){
		cin >> a >> b;
		int x = findSet(a), y = findSet(b);
		if (sameset(x,y)){
			cnt++;
		}
		else {
			s.erase(s.find(sz[x]));
			s.erase(s.find(sz[y]));
			s.insert(sz[x] + sz[y]);
			mergeset(x,y);

		}
		auto it = s.end();
		it--;
		ll ans = 0;
		for (int i=0; i<=cnt; i++){
			ans += *it;
			it--;
		}
		cout << ans -1 <<"\n";
	}
}