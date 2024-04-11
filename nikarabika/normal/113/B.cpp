#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<LL, LL> pie;

#define MP make_pair
#define L first
#define R second

const int maxn = 2e3 + 85 - 69;
const LL D = 1e9 + 7;
LL hash[2][maxn];
LL hashp[2], hasht[2];
LL P[2][maxn], base[2] = {37, 101};
string s, t, p;

LL H(int b, int e){
	return (b == 0) ? hash[0][e] : (((hash[0][e] - hash[0][b - 1] * P[0][e - b + 1]) % D) + D) % D;
}

LL H2(int b, int e){
	return (b == 0) ? hash[1][e] : (((hash[1][e] - hash[1][b - 1] * P[1][e - b + 1]) % D) + D) % D;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> p >> t;
	if(p.size() > s.size() or t.size() > s.size()){
		cout << 0 << endl;
		return 0;
	}
	P[0][0] = P[1][0] = 1;
	hash[0][0] = hash[1][0] = s[0] - 'a' + 1;
	for(int i = 0; i < 2; i++){
		for(int j = 1; j < s.size(); j++){
			hash[i][j] = (hash[i][j - 1] * base[i] + s[j] - 'a' + 1) % D;
			P[i][j] = (P[i][j - 1] * base[i]) % D;
		}
	}
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < p.size(); j++)
			hashp[i] = (hashp[i] * base[i] + p[j] - 'a' + 1) % D;
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < t.size(); j++)
			hasht[i] = (hasht[i] * base[i] + t[j] - 'a' + 1) % D;
	int ans = 0;
	for(int l = max(p.size(), t.size()); l <= s.size(); l++){
		set <pie> S;
		for(int i = 0; i + l <= s.size(); i++)
			if(H(i, i + p.size() - 1) == hashp[0] and H2(i, i + p.size() - 1) == hashp[1])
				if(H(i + l - t.size(), i + l - 1) == hasht[0] and H2(i + l - t.size(), i + l - 1) == hasht[1])
					S.insert(MP(H(i, i + l - 1), H2(i, i + l - 1)));
		ans += (int)S.size();
	}
	cout << ans << endl;
	return 0;
}