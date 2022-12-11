#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())


int main(){
	fastIO;
	int n, l, a;
	cin >> n >> l >> a;
	int ls = -1;
	int ans = 0;
	int ti, li;
	int dif;
	for(int i = 0; i < n; i ++ ){
		cin >> ti >> li;
		dif = ti - 1 - ls;
		ans += dif / a;
		ls = ti + li - 1;
	}
	ans += (l - ls - 1) / a;
	cout << ans;
	return 0;
}