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

const int N = (int)1e5 + 9;
ld cur[N];

void init(){
	for(int i = 0;i<N;i++)
		cur[i] = (ld)1e10;
}

int main(){
	fastIO;
	int n;
	ld b;
	init();
	cin >> n >> b;
	for(int i = 0;i<n;i++)
		cin >> cur[i];
	int y;
	ld ans = 0;
	for(int i = 0;i<n;i++){
		y = upper_bound(cur,cur+N,cur[i] + b) - cur;
		--y;
		if(y - i < 2)
			continue;
		ans = max(ans,(cur[y]-cur[i+1]) / (cur[y]-cur[i]));
	}
	if(ans == 0)
		cout << -1;
	else
		cout << fixed << setprecision(10) << ans;
	return 0;
}