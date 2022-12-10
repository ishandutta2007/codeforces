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

const int maxn = 1000 + 85 - 69;
int ans[maxn][maxn],
	cnt[3],
	put2[maxn],
	n, m;
bool tip[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			string str;
			cin >> str;
			if(str == "00") cnt[0]++;
			else if(str == "11") cnt[2]++;
			else cnt[1]++;
		}
	}
	for(int j = 0; j < m; j++)
		put2[j] = cnt[2] / m + (j < cnt[2] % m);
	for(int j = m - 1; j >= cnt[2] % m; j--)
		if(cnt[1]){
			ans[put2[j]][j] = (tip[j] ? 10 : 1);
			tip[j] = 1;
			cnt[1]--;
		}
	for(int i = put2[m - 1] + 1; i < n; i++)
		for(int j = m - 1; j >= 0; j--)
			if(cnt[1]){
				ans[i][j] = (tip[j] ? 10 : 1);
				tip[j] = !tip[j];
				cnt[1]--;
			}
	for(int i = 0; i < n; i++, cout << '\n')
		for(int j = 0; j < m; j++)
			if(i < put2[j])
				cout << "11 ";
			else if(ans[i][j] == 1)
				cout << "01 ";
			else if(ans[i][j] == 10)
				cout << "10 ";
			else
				cout << "00 ";
	return 0;
}