//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()
#define cos cost

const int maxn = 130,
	  maxe = maxn * 26 * 2;
int too[maxe],
	cap[maxe],
	cos[maxe],
	prv[maxe],
	hed[maxn],
	dis[maxn],
	par[maxn],
	n, m, sou, syn;
bool inq[maxn];
string t;
queue<int> q;

void adde(int u, int v, int uv, int cos, int vu = 0){
	too[m] = v, cap[m] = uv, (::cos)[m] = +cos, prv[m] = hed[u], hed[u] = m++;
	too[m] = u, cap[m] = vu, (::cos)[m] = -cos, prv[m] = hed[v], hed[v] = m++;
}

void spfa(void){
	memset(dis, 63, sizeof dis);
	memset(par, -1, sizeof par);
	memset(inq, 0, sizeof inq);
	dis[sou] = 0;
	q.push(sou);
	inq[sou] = true;
	while(sz(q)){
		int u = q.front();
		q.pop();
		inq[u] = false;
		for(int e = hed[u]; ~e; e = prv[e]){
			int v = too[e],
				w = cos[e];
			if(cap[e] == 0 or dis[u] + w >= dis[v]) continue;
			dis[v] = dis[u] + w;
			par[v] = e^1;
			if(!inq[v]){
				q.push(v);
				inq[v] = true;
			}
		}
	}
	return;
}

void decrea(int u){
	if(u ^ sou){
		int e = par[u];
		cap[e^0]++;
		cap[e^1]--;
		decrea(too[e]);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(hed, -1, sizeof hed);
	cin >> t
		>> n;
	sou = n + 26;
	syn = n + 27;
	{
		int ch[26];
		memset(ch, 0, 26 * 4);
		for(auto c : t)
			ch[c - 'a']++;
		for(int i = 0; i < 26; i++)
			if(ch[i])
				adde(n + i, syn, ch[i], 0);
	}
	for(int i = 0; i < n; i++){
		string str;
		int cnt;
		cin >> str >> cnt;
		int ch[26];
		memset(ch, 0, 26 * 4);
		for(auto c : str)
			ch[c - 'a']++;
		for(int j = 0; j < 26; j++)
			if(ch[j])
				adde(i, n + j, ch[j], 0);
		if(cnt) adde(sou, i, cnt, i + 1);
	}
	int ans = 0;
	for(int i = 0; i < sz(t); i++){
		spfa();
		if(par[syn] == -1){
			cout << -1 << endl;
			return 0;
		}
		ans += dis[syn];
		decrea(syn);
	}
	cout << ans << endl;
	return 0;
}