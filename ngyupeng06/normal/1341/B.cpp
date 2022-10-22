#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

long long n, k, m, t, a, b, c, d, arr[200005];

int ispeak(int x){
	if (arr[x] > arr[x-1] && arr[x] > arr[x+1]) return 1;
	else return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> k;
		for (int i=1; i<=n; i++){
			cin >> arr[i];
		}
		long long ans = 0, ans1 = 0;
		long long p = 1;
		for (int i=2; i<=k-1; i++){
			p += ispeak(i);
		}
		ans1 = p;
		ans = 1;
		for (int i=2; i<=n-k+1; i++){
			p-=ispeak(i);
			p+=ispeak(i+k-2);
			if (p > ans1){
				ans1 = p;
				ans = i;
			}
		}
		cout << ans1 << " " << ans << "\n";
	}
}