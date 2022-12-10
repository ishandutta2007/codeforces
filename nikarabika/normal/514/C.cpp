#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn = 3e5 + 85 - 69, maxs = 6e5 + 85 - 69;
set <LL> all, all2;
const LL base = 37, base2 = 257, D = 1e9 + 7;
LL P[maxs], P2[maxs];
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	P[0] = 1;
	P2[0] = 1;
	for(int i = 1; i < maxs; i++){
		P[i] = (P[i - 1] * base) % D;
		P2[i] = (P2[i - 1] * base2) % D;
	}
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		LL hash = 0, hash2 = 0;
		for(int j = 0; j < s.size(); j++)
			hash = (hash * base + s[j] - 'a' + 1) % D,
			hash2 = (hash2 * base2 + s[j] - 'a' + 1) % D;
		all.insert(hash);
		all2.insert(hash2);
	}
	for(int i = 0; i < m; i++){
		string t;
		cin >> t;
		LL hash = 0, hash2 = 0;
		for(int j = 0; j < t.size(); j++){
			hash = (hash * base + t[j] - 'a' + 1) % D;
			hash2 = (hash2 * base2 + t[j] - 'a' + 1) % D;
		}
		for(char x = 'a'; x <= 'c'; x++){
			for(int j = 0; j < t.size(); j++) if(t[j] != x){
				if(all.find((((hash - (t[j] - x) * P[t.size() - j - 1]) % D) + D) % D) != all.end() and
						all2.find((((hash2 - (t[j] - x) * P2[t.size() - j - 1]) % D) + D) % D) != all2.end()){
					cout << "YES\n";
					goto TheEnd;
				}
			}
		}
		cout << "NO\n";
TheEnd:;
	}
	return 0;
}