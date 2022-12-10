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

string s;
int n, dx[1000], dy[1000];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	for(int i = 0; i < n; i++){
		switch(s[i]){
			case 'U':
				dy[i + 1] = dy[i] + 1;
				dx[i + 1] = dx[i];
				break;
			case 'D':
				dy[i + 1] = dy[i] - 1;
				dx[i + 1] = dx[i];
				break;
			case 'R':
				dx[i + 1] = dx[i] + 1;
				dy[i + 1] = dy[i];
				break;
			case 'L':
				dx[i + 1] = dx[i] - 1;
				dy[i + 1] = dy[i];
				break;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < i; j++)
			if(dx[i] == dx[j] and dy[i] == dy[j])
				ans++;
	cout << ans << endl;
	return 0;
}