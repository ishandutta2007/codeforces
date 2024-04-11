#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

const int B = 32;
ll P[B];

void init(){
	P[0] = 1;
	for(int i = 1;i<B;i++)
		P[i] = P[i-1] * 2;
}

int main(){
	init();
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0;i<n;i++)
		cin >> arr[i];
	ll ans = 0;
	for(int i = 1;i<B;i++){
		unordered_map<ll,int>cnt;
		for(int j = 0;j<n;j++){
			ans += cnt[P[i]-arr[j]];
			cnt[arr[j]]++;
		}
	}
	cout << ans << "\n";
	return 0;
}