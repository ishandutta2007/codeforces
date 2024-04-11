#include <bits/stdc++.h>

using namespace std;

const int N = 200050;
const long long mod = 1000004249;

int n;
int l[N];
int r[N];
char a[N];
int lcp[N];
long long pw[N];
char forbidden[N];
long long hashes[N];

long long get(int l, int r){
	return (hashes[r] - hashes[l - 1] * pw[r - l + 1] + mod * mod) % mod;
}

int LCP(int x, int y){
	int low = 0, high = min(n - x + 1, n - y + 1) - 1, ans = -1;
	while(low <= high){
		int mid = (low + high) >> 1;
		if(get(x, x + mid) == get(y, y + mid)){
			ans = mid;
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	return ans + 1;
}

bool cmp(int x, int y){
	int p = LCP(x, y);
	if(p == min(n - x + 1, n - y + 1) + 1){
		return (x == max(x, y));
	}
	return a[x + p] < a[y + p];
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d%s%s", &n, a + 1, forbidden + 1);

	reverse(a + 1, a + n + 1);
	reverse(forbidden + 1, forbidden + n + 1);

	vector < int > lst;
	for(int i = 1; i <= n; ++i){
		if(forbidden[i] == '0'){
			lst.push_back(i);
		}
	}

	pw[0] = 1;
	for(int i = 1; i <= n; ++i){
		pw[i] = pw[i - 1] * 37 % mod;
		hashes[i] = (hashes[i - 1] * 37 + a[i] - 'a') % mod; 
	}


	sort(lst.begin(), lst.end(), cmp);

	long long ans = 0;

	if(lst.size() == 0){
		cout << 0;
		return 0;
	}

	ans = n - lst[0] + 1;
	for(int i = 1; i < lst.size(); ++i){
		lcp[i] = LCP(lst[i], lst[i - 1]);
		ans = max(ans, 1LL * n - lst[i] + 1);
	}


	stack < int > curr;

	for(int i = 1; i < lst.size(); ++i){
		while(!curr.empty() && lcp[i] < lcp[curr.top()]){
			r[curr.top()] = i - 1;
			curr.pop();
		}
		if(curr.empty()) l[i] = 1;
		else l[i] = curr.top() + 1;
		curr.push(i);
	}
	while(!curr.empty()){
		r[curr.top()] = lst.size() - 1;
		curr.pop();
	}

	for(int i = 1; i < lst.size(); ++i){
		ans = max(ans, 1LL * lcp[i] * (r[i] - l[i] + 2));
	}



	cout << ans;

	return 0;
}