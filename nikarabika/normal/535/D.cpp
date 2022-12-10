#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define L first
#define R second

typedef long long int LL;
typedef pair<LL, LL> pie;

const int maxn = 1e6 + 10;
LL hash[maxn], P[maxn], n, m;
const LL base = 47, Mod = 1e9 + 7;
string p;
stack<pie> S;
int y[maxn];

LL H(int s, int e){
	return (s == 0) ? hash[e] : (((hash[e] - hash[s - 1] * P[e - s + 1]) % Mod) + Mod) % Mod;
}

LL Ans(){
	LL x = n;
	while(S.size()){
		pie X = S.top();
		S.pop();
		x -= X.R - X.L;
	}
	LL an = 1;
	for(int i = 1; i <= x; i++)
		an = (an * 1LL * 26) % Mod;
	return an;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> p;
	for(int i = 0; i < m; i++){
		cin >> y[i];
		y[i]--;
	}
	P[0] = 1;
	hash[0] = p[0] - 'a' + 1;
	for(int i = 1; i < p.size(); i++){
		P[i] = (P[i - 1] * base) % Mod;
		hash[i] = (hash[i - 1] * base + p[i] - 'a' + 1) % Mod;
	}
	if(m >= 1) 
		S.push(MP(y[0], y[0] + p.size()));
	for(int i = 1; i < m; i++){
		if(y[i] < y[i - 1] + p.size()){
			int d = y[i - 1] + p.size() - y[i];
			if(H(p.size() - d, p.size() - 1) != H(0, d - 1)){
				cout << 0 << endl;
				return 0;
			}
		}
		pie X = MP(y[i], y[i] + p.size());
		if(S.size() and y[i] < S.top().R){
			X = S.top();
			S.pop();
		}
		S.push(MP(X.L, y[i] + p.size()));
	}
	cout << Ans() << endl;
	return 0;
}