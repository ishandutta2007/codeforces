#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = 505;
bool ok[N][N];

int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct Operation{
	char v1;
	int v2;
	int v3;
};

vector<Operation> answer;

void dfs(int xi, int yi, int state){
	if(ok[xi][yi])
		return;
	ok[xi][yi] = true;
	answer.push_back({'B', xi, yi});
	for(int i = 0; i < 4; i ++ )	
		dfs(xi + d[i][0], yi + d[i][1], 1);
	if(state != 0){
		answer.push_back({'D', xi, yi});
		answer.push_back({'R', xi, yi});
	}
}

int main(){
	fastIO;
	memset(ok, true, sizeof ok);
	int n, m;
	cin >> n >> m;
	char s;
	for(int i = 1; i <= n; i ++ ){
		for(int j = 1;j <= m ; j ++ ){
			cin >> s;
			if(s == '.')
				ok[i][j] = false;
		}
	}
	for(int i = 1; i <= n;i ++ ){
		for(int j = 1;j <= m; j ++ ){
			dfs(i, j, 0);
		}
	}
	cout << answer.size() << "\n";
	for(auto x : answer){
		cout << x.v1 << " " << x.v2 << " " << x.v3 << "\n";
	}
	return 0;
}