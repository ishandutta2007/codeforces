#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())

const int N = (int)4e5 + 9;

map<string, int> mp;
int p;

int cntR[N];
int len[N];

string turn(string t){
	for(char &x : t){
		if(x >= 'A' and x <= 'Z'){
			x += 32;
		}
	}
	return t;
}

void add(string  t){
	if(mp[t] != 0)
		return;
	mp[t] = ++ p;
	for(char &x : t){
		cntR[p] += (x == 'r');
	}
	len[p] = t.size();
}

vector<int> T[N];

struct Node{
	int index;
	int rcount;
	int leng;
	bool operator< (const Node& T) const {
		if(rcount == T.rcount){
			return leng > T.leng;
		}
		else{
			return rcount > T.rcount;
		}
	}
};

void Dijikstra(){
	priority_queue<Node> q;
	for(int i = 1; i <= p; i ++){
		q.push({i, cntR[i], len[i]});
	}
	Node cr;
	int rcnt;
	int ln;
	int nr;
	while(!q.empty()){
		cr = q.top();
		q.pop();
		nr = cr.index;
		rcnt = cr.rcount;
		ln = cr.leng;
		if(cntR[nr] != rcnt or len[nr] != ln)
			continue;
		for(auto x : T[nr]){
			if(cntR[x] > rcnt or (cntR[x] == rcnt and len[x] > ln)){
				cntR[x] = rcnt;
				len[x] = ln;
				q.push({x, rcnt, ln});
			}
		}
	}
}

int main(){
	fastIO;
	int m;
	cin >> m;
	string s;
	int per[m];
	for(int i = 0; i < m ; i ++ ){
		cin >> s;
		s = turn(s);
		add(s);
		per[i] = mp[s];
	}
	int n;
	cin >> n;
	string u, v;
	int e1, e2;
	for(int i = 0 ; i < n; i ++ ){
		cin >> u >> v;
		u = turn(u);
		v = turn(v);
		add(u);
		add(v);
		e1 = mp[u];
		e2 = mp[v];
		T[e2].push_back(e1);
	}
	Dijikstra();
	ll cr = 0;
	ll tl = 0;
	for(int i = 0 ; i < m ;i ++ ){
		cr += cntR[per[i]];
		tl += len[per[i]];
	}
	cout << cr << " " << tl << "\n";
	return 0;
}