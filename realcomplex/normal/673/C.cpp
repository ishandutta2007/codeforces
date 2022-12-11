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

const int N = 5005;
int cnt[N];
int ans[N];

int main(){
	fastIO;
	int n;
	cin >> n;
	int t[n];
	for(int i = 0;i<n;i++)
		cin >> t[i];
	int maxs = 0,ix = 0;
	for(int i = 0;i<n;i++){
		for(int j = 1;j<=n;j++)
			cnt[j] = 0;
		maxs = 0,ix = 0;
		for(int j = i;j>=0;j--){
			cnt[t[j]]++;
			if(cnt[t[j]] > maxs or (cnt[t[j]] == maxs and t[j] < ix)){
				maxs = cnt[t[j]];
				ix = t[j];
			}
			ans[ix]++;
		}
	}
	for(int i = 1;i<=n;i++)
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}