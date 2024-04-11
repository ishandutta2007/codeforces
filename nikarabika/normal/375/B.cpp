#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 5e3 + 10;
int n, m;
char a[maxn][maxn];
int x[maxn];
vector<int> v[maxn];

int main(){
    scanf("%d%d", &n, &m);
    getchar();
    for(int i = 0; i < n; i++)
		for(int j = 0; j <= m; j++)
			a[i][j] = getchar();
    int ans = 0;
	for(int i = 0; i < n; i++)
		v[m].PB(0);
    for(int j = m; j > 0; j--){
		for(int i = 0; i < n; i++)
			v[j - 1].PB((a[i][j - 1] == '0') ? 0 : v[j][i] + 1);
		sort(v[j].begin(), v[j].end());
		for(int i = 0; i < n; i++)
			ans = max(ans, v[j][i] * (n - i));
	}
	sort(v[0].begin(), v[0].end());
	for(int i = 0; i < n; i++)
		ans = max(ans, v[0][i] * (n - i));
        
    cout << ans << endl;
    return 0;
}