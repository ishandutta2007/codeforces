#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double db;

#define fi first
#define se second
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())
#define mp make_pair

const int AL = 26;

int rep[AL][AL];

int main(){
	fastIO;
	string a, b;
	cin >> a >> b;
	if(a.size() != b.size()){
		cout << -1 << "\n";
		return 0;
	}
	int m;
	cin >> m;
	char aj, bj;
	int cost;
	for(int i = 0; i < AL; i ++ ){
		for(int j = 0 ;j < AL; j ++ ){
			rep[i][j] = (int)1e9 + 9;
		}
		rep[i][i] = 0;
	}
	for(int i = 0 ;i < m ; i ++ ){
		cin >> aj >> bj >> cost;
		rep[aj - 'a'][bj - 'a'] = min(rep[aj - 'a'][bj - 'a'], cost);
	}
	for(int k = 0; k < AL; k ++ ){
		for(int i = 0; i < AL ; i ++ ){
			for(int j = 0 ;j < AL; j ++ ){
				rep[i][j] = min(rep[i][j], rep[i][k] + rep[k][j]);
			}
		}
	}
	int ans = 0;
	int rt;
	int v1, v2;
	char go;
	vector<char> out;
	for(int i = 0 ;i < a.size(); i ++ ){
		v1 = a[i] - 'a';
		v2 = b[i] - 'a';
		rt = (int)1e9 + 9;
		go = '!';
		for(int j = 0 ;j < AL; j ++ ){
			if(rep[v1][j] + rep[v2][j] < rt){
				rt = rep[v1][j] + rep[v2][j];
				go = char(j + 'a');
			}
		}
		if(go == '!'){
			cout << -1 << "\n";
			return 0;
		}
		ans += rt;
		out.push_back(go);
	}
	cout << ans << "\n";
	for(auto x : out)
		cout << x;
	return 0;
	
}