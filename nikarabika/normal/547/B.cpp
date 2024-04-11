#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pie;

#define MP make_pair
#define L first
#define R second

const int maxn = 2e5 + 85;
int n, Max;
int a[maxn], dp[maxn], pd[maxn], ans[maxn];
pie an[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	stack<pie> s;
	for(int i = 0; i < n; i++){
		while(s.size() and s.top().L >= a[i])
			s.pop();
		if(!s.size())
			dp[i] = i;
		else
			dp[i] = i - s.top().R - 1;
		s.push(MP(a[i], i));
	}
	while(s.size()) s.pop();
	for(int i = n - 1; i >= 0; i--){
		while(s.size() and s.top().L >= a[i])
			s.pop();
		if(!s.size())
			pd[i] = n - i - 1;
		else
			pd[i] = s.top().R - i - 1;
		s.push(MP(a[i], i));
	}
	for(int i = 0; i < n; i++)
		an[i] = MP(dp[i] + pd[i] + 1, a[i]);
	sort(an, an + n);
	reverse(an, an + n);
	int p = 0;
	for(int i = n; i > 0; i--){
		while(p < n and i <= an[p].L)
			Max = max(Max, an[p++].R);
		ans[i] = Max;
	}
	for(int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}