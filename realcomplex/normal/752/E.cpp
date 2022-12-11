#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

typedef pair<string,int> si;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

const int MX = (int)1e7 + 12345;
int cnt[MX];
int rem[MX];

int main(){
	fastIO;
	int n;
	ll k;
	cin >> n >> k;
	ll sum = 0;
	ll total = 0;
	int cur;
	for(int i = 0 ;i<n;i++){
		cin >> cur;
		cnt[cur]++;
		sum += cur;
	}
	if(sum < k){
		cout << -1 << "\n";
		return 0;
	}
	int l,r;
	for(int i = MX-1;i>=2;i--){
		l = i/2;
		r = (i+1)/2;
		total += cnt[i];
		total -= rem[i];
		if(total >= k){
			cout << i << "\n";
			return 0;
		}
		cnt[l] += cnt[i];
		rem[r] += cnt[i];
		cnt[r] += cnt[i];
	}
	cout << 1 << "\n";
	return 0;
}