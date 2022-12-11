
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;

int sz[N];
int pi[N];
ll mz[N];

set<pii> sets;

struct Edge{
	int A;
	int B;
	ll W;
	bool operator< (Edge V){
		return W < V.W;
	}
};

int fin(int u){
	if(u == pi[u])
		return u;
	return pi[u] = fin(pi[u]);
}

bool check(int a, int b){
	a = fin(a);
	b = fin(b);
	if(a == b)
		return false;
	return true;
}

void merge(int a, int b){
	a = fin(a);
	b = fin(b);
	if(sz[a] > sz[b])
		swap(a, b);
	sets.erase(mp(mz[a], a));
	sets.erase(mp(mz[b], b));
	sz[b] += sz[a];
	pi[a] = b;
	mz[b] = min(mz[a], mz[b]);
	sets.insert(mp(mz[b], b));
}

int main(){
	fastIO;
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n; i ++ ){
		sz[i] = 1;
		pi[i] = i;
		cin >> mz[i];
		sets.insert(mp(mz[i], i));
	}
	vector<Edge> T;
	Edge cur;
	for(int i = 0 ; i < m ; i ++ ){
		cin >> cur.A >> cur.B >> cur.W;
		T.push_back(cur); 
	}
	sort(T.begin() , T.end());
	int p = 0;
	ll op1, op2;
	ll answ = 0;
	int m1, m2;
	int m3, m4;
	while(sets.size() > 1){
		op1 = (ll)1e15;
		op2 = (ll)1e15;
		auto it = sets.begin();
		op1 = it -> fi;
		m1 = it -> se;
		it ++ ;
		op1 += it -> fi;
		m2 = it -> se;
		while(p < m){
			if(!check(T[p].A, T[p].B)){
				p ++;
				continue;
			}
			m3 = T[p].A;
			m4 = T[p].B;
			op2 = T[p].W;
			break;
		}
		if(op1 < op2){
			merge(m1, m2);
			answ += op1;
		}
		else{
			merge(m3, m4);
			answ += op2;
			p ++ ;
		}
	}
	cout << answ;
	return 0;
}