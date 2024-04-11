#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 3e5 + 85 - 69;
int n, m;
vector<int> v[maxn];
int en[maxn], f[maxn];
bool team[maxn];
set<int> s;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	while(m--){
		int fi, se;
		cin >> fi >> se;
		v[fi].PB(se);
		v[se].PB(fi);
		en[fi]++, en[se]++;
		if(en[fi] == 2)
			s.insert(fi);
		if(en[se] == 2)
			s.insert(se);
	}
	while(s.size()){
		int x = *s.begin();
		s.erase(s.begin());
		for(int i = 0; i < v[x].size(); i++){
			int y = v[x][i];
			if(team[x] == team[y]){
				en[y]--, en[x]--;
				if(en[y] == 1)
					s.erase(y);
			}
			else{
				en[y]++, en[x]++;
				if(en[y] == 2)
					s.insert(y);
			}
		}
		team[x] = !team[x];
	}
	for(int i = 1; i <= n; i++)
		cout << team[i];
	cout << endl;
	return 0;
}