//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Izzz wayTn' 230u :)

const int maxn = 5e5 + 85 - 69;
int a[maxn];
int n, ans;

int solve(int st, int en, bool dir = true){
	if(en - st == 0){
		if(!dir)
			a[st] = 1 - a[st];
		if((st - 1 != -1 and a[st] != a[st - 1]) and (st + 1 != n and a[st] != a[st + 1]))
			a[st] = 1 - a[st];
		return 0;
	}
	if(!dir){
		a[st] = 1 - a[st];
		a[en] = 1 - a[en];
	}
	if(en - st == 1)
		return 0;
	return 1 + solve(st + 1, en - 1, !dir);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i + 1 < n; i++){
		int p = i;
		while(p + 1 < n and a[p] != a[p + 1])
			p++;
		ans = max(ans, solve(i, p));
		i = p;
	}
	cout << ans << endl;
	for(int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}