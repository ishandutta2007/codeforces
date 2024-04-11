#include <iostream>
#include <string>
#include <algorithm>

#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second
#define p 1000000007

using namespace std;
typedef long long ll;

int cnt[1000][5];
int main(){
	for(int i=0;i<1000;i++){
		fill(cnt[i], cnt[i]+5, 0);
	}
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		for(int j=0;j<m;j++){
			cnt[j][s[j] - 'A']++;
		}
	}
	int ans = 0;
	for(int i=0;i<m;i++){
		int sc;
		cin >> sc;
		ans += sc * *max_element(cnt[i], cnt[i] + 5);
	}
	cout << ans;
	return 0;
}