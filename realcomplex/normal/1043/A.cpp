#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())

int main(){
	fastIO;
	int n;
	cin >> n;
	int a[n];
	int mx = 0;
	for(int i = 0 ;i < n;i ++ ){
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	int p1, p2;
	for(int k = mx ; k <= 10000; k ++ ){
		p1 = 0, p2 = 0;
		for(int i = 0 ;i < n;i ++ ){
			p2 += a[i];
			p1 += k - a[i];
		}
		if(p1 > p2){
			cout << k;
			return 0;
		}
	}
	return 0;
}