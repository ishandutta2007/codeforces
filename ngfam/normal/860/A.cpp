#include <bits/stdc++.h>

using namespace std;

const int N = 3030;

int f[N];
int p[N];
int typo[N];
	string x;
int n;

bool minimize(int &u, int v){
	if(u > v){
		u = v;
		return true;
	}
	return false;
}

bool ok(char c){
	return (c != 'a' && c != 'i' && c != 'u' && c != 'o' && c != 'e');
}

void backtrack(int u){
	if(u == 0){
		return;
	}
	backtrack(p[u]);
	for(int i = p[u] + 1; i <= u; ++i){
		cout << x[i];
	}
	if(u != n){
		cout << ' ';
	}
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	cin >> x;

	 n = x.size();

	x = " " + x;

	for(int i = 0; i <= n; ++i){
		typo[i] = n;
	}

	for(int i = 1; i <= n; ++i){
		map < char, bool > done;
		int j = i;
		while(j <= n && ok(x[j])){
			done[x[j]] = 1;
			//typo[i] = j;
			if(done.size() >= 2 && j - i >= 2){
				typo[i] = j - 1;
				break;
			}
			++j;
		}
	}


	memset(f, 60, sizeof f);
	f[0] = 0;

	for(int i = 0; i < n; ++i){
		int j = i + 1;
		int pter = typo[j];

		while(j <= pter){
			if(minimize(f[j], f[i] + 1)){
				p[j] = i;
			}
			++j;
			pter = min(pter, typo[j]);
		}
	}

	backtrack(n);


	return 0;
}