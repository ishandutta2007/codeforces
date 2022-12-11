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

const int N = 1005;
int cnt[N];

int main(){
	fastIO;
	int m, n;
	cin >> n >> m;
	int u, v;
	for(int i = 0; i < m; i ++ ){
		cin >> u >> v;
		cnt[u] ++ ;
		cnt[v] ++ ;
	}
	cout << n - 1 << "\n";
	for(int i = 1; i <= n;i ++ ){
		if(cnt[i] == 0){
			for(int j = 1; j <= n; j ++ ){
				if(i != j)
					cout << i << " " << j << "\n";
			}
			return 0;
		}
	}
	return 0;
}