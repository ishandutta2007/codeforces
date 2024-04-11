#include <bits/stdc++.h>

using namespace std;

const int maxn = 500 + 10;
int n;
long long int a[maxn][maxn], x[maxn];
bool mark[maxn];
vector<long long> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	for(int i = 1; i <= n; i++)
		cin >> x[i];
	for(int k = n; k > 0; k--){
		long long int ans = 0;
		mark[x[k]] = true;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				a[i][j] = min(a[i][j], a[i][x[k]] + a[x[k]][j]);
				if(mark[i] and mark[j])
					ans += a[i][j];
			}
		}
		v.push_back(ans);
	}
	for(int i = v.size() - 1; i >= 0; i--)
		cout << v[i] << ' ';
	cout << endl;
	return 0;
}