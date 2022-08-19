#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int nax = 1e6 + 5;
int par[nax];
ll t[nax];
multiset<ll> BEST;
ll interior[nax]; // the income from my fanpage and my children's fanpages
					// (so, doesn't include income from my parent)

struct cmp {
	bool operator ()(int a, int b) {
		if(interior[a] != interior[b])
			return interior[a] < interior[b];
		return a < b;
	}
};

struct Children {
	set<int,cmp> s;
	vector<ll> getBest() {
		vector<ll> ret;
		if(!s.empty())
			ret.push_back(interior[*s.begin()]);
		if((int) s.size() >= 2) {
			auto it = s.end();
			--it;
			ret.push_back(interior[*it]);
		}
		return ret;
	}
	void insert(int a) {
		s.insert(a);
	}
	void erase(int a) {
		s.erase(a);
	}
	int degree; // not always equal to s.size(), to allow more comfortable updates
} children[nax];

ll value_for_other(int a) {
	return t[a] / (2 + children[a].degree);
}
ll value_for_self(int a) {
	return t[a] - (1 + children[a].degree) * value_for_other(a);
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", &t[i]);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &par[i]);
		children[par[i]].degree++;
		children[par[i]].insert(i);
	}
	
	// calculate initial values of interior[n]
	for(int i = 1; i <= n; ++i) {
		children[par[i]].erase(i);
		
		// income from my fanpage
		interior[i] = value_for_self(i);
		// and from children's fanpages
		for(int x : children[i].s)
			interior[i] += value_for_other(x);
				
		children[par[i]].insert(i);
	}
	
	// fill BEST
	for(int i = 1; i <= n; ++i) {
		vector<ll> values = children[i].getBest();
		for(ll value : values)
			BEST.insert(value + value_for_other(i));
	}
	
	// read and process queries
	while(q--) {
		int type;
		scanf("%d", &type);
		if(type == 1) {
			int a, b;
			scanf("%d%d", &a, &b);
			set<int> interesting = set<int>{a, b, par[a], par[b], par[par[a]]};
			set<int> more = interesting;
			for(int x : interesting) more.insert(par[x]);
			
			for(int x : more) {
				vector<ll> values = children[x].getBest();
				for(ll value : values) {
					auto it = BEST.find(value + value_for_other(x));
					assert(it != BEST.end());
					BEST.erase(it);
				}
			}
			
			for(int x : interesting)
				children[par[x]].erase(x);
			
			for(int rep = -1; rep <= 1; rep += 2) { // first -1, then 1
				for(int x : interesting) {
					interior[x] += rep * value_for_self(x);
					for(int y : interesting)
						if(par[y] == x)
							interior[x] += rep * value_for_other(y);
				}
				
				if(rep == -1) {
					children[par[a]].degree--;
					par[a] = b;
					children[par[a]].degree++;
				}
					
			}
			
			for(int x : interesting)
				children[par[x]].insert(x);
			
			for(int x : more) {
				vector<ll> values = children[x].getBest();
				for(ll value : values)
					BEST.insert(value + value_for_other(x));
			}
		}
		else if(type == 2) {
			int a;
			scanf("%d", &a);
			printf("%lld\n", interior[a] + value_for_other(par[a]));
		}
		else {
			printf("%lld ", *BEST.begin());
			auto it = BEST.end();
			--it;
			printf("%lld\n", *it);
		}
	}
	return 0;
}