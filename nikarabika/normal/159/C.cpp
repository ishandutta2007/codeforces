#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxk = 2e3 + 2, maxsz = 102, maxt = 2000 * 100 + 10;
int T[maxt * 4];
vector<int> v[26], a[26];
string s;
int k, n, Tn;
bool mark[maxk][maxsz];

int query(int idx, int L = 0, int R = Tn, int id = 1){
	T[id]++;
	if(R - L == 1)
		return L;
	int mid = (L + R) >> 1;
	if(idx <= (mid - L) - T[id * 2 + 0])
		return query(idx, L, mid, id * 2 + 0);
	else
		return query(idx - ((mid - L) - T[id * 2 + 0]), mid, R, id * 2 + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> k >> s >> n;

	for(int i = 0; i < s.size(); i++)
		a[s[i] - 'a'].PB(i);

	for(int i = 0; i < n; i++){
		int p;
		char c;
		cin >> p >> c;
		v[c - 'a'].PB(p);
	}

	for(int i = 0; i < 26; i++){
		Tn = 1LL * a[i].size() * k;
		for(int j = 0; j < v[i].size(); j++){
			int x = query(v[i][j]);
			mark[x / a[i].size()][a[i][x % a[i].size()]] = true;
		}
		memset(T, 0, sizeof T);
	}

	for(int i = 0; i < k; i++)
		for(int j = 0; j < s.size(); j++)
			if(!mark[i][j])
				cout << s[j];
	cout << endl;
	return 0;
}