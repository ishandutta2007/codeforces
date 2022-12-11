#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = (int)2e5 + 9;

int cnt[N];

int main(){
	fastIO;
	int n, s;
	cin >> n >> s;
	-- s;
	int p[n];
	for(int i = 0;i < n;i ++ )
		cin >> p[i];
	int ans = 0;
	if(p[s] != 0){
		p[s] = 0;
		ans ++ ;
	}
	for(int i = 0;i < n; i ++ ){
		if(i != s)
			cnt[p[i]] ++ ;
	}
	int r = n - 1;
	for(int i = 1; i <= n - 1; i ++ ){
		if(cnt[i] == 0){
			if(cnt[0] > 0){
				cnt[i] ++ ;
				cnt[0] -- ;
				ans ++ ;
			}
			else{
				while(cnt[r] == 0 and r > i){
					-- r;
				}
				if(r <= i)
					break;
				cnt[i] ++ ;
				cnt[r] -- ;
				ans ++ ;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}