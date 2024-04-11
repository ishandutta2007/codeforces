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

int main(){
	fastIO;
	int n;
	cin >> n;
	ll h[n];
	ll t[n];
	for(int i = 0;i<n;i++){
		cin >> h[i];
		t[i] = h[i];
	}
	for(int j = n-2;j>=0;j--){
		t[j] = max(t[j],t[j+1]-1);
	}
	for(int j = 1;j<n;j++){
		t[j] = max(t[j],t[j-1]);
	}
	ll ans = 0;
	for(int j = 0;j<n;j++){
		ans += t[j] - h[j];
	}
	cout << ans;
	return 0;
}