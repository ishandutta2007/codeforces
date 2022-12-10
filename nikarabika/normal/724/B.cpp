//sobskdrbhvk
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

const int maxn = 50;
int a[maxn][maxn],
	ord[maxn];
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	iota(ord, ord + m, 0);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	for(int j1 = 0; j1 < m; j1++){
		for(int j2 = j1; j2 < m; j2++){
			swap(ord[j1], ord[j2]);
			bool cancan = true;
			for(int i = 0; i < n; i++){
				bool row = false;
				for(int j = 0; j < m; j++)
					for(int jj = j; jj < m; jj++){
						swap(a[i][j], a[i][jj]);
						bool can = true;
						for(int k = 0; k + 1 < m; k++)
							if(a[i][ord[k]] > a[i][ord[k + 1]]){
								can = false;
								break;
							}
						swap(a[i][j], a[i][jj]);
						if(can){
							row = true;
							goto gell;
						}
					}
gell:
				if(!row){
					cancan = false;
					break;
				}
			}
			if(cancan){
				cout << "YES" << endl;
				return 0;
			}
			swap(ord[j1], ord[j2]);
		}
	}
	cout << "NO" << endl;
	return 0;
}