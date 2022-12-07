#include <bits/stdc++.h>

using namespace std;

const int N = 300100;
const int base = 330;

struct data{
	int u;
	int v;
	int idx;

	void read(int i){
		scanf("%d%d", &u, &v);
		--u;
		idx = i;
	}
};

bool cmp(data u, data v){
	return u.v < v.v;
}

int n, k, q;
int t[N];
long long a[N];
long long add[N];
long long sub[N];
long long ans[N];
vector < data > lst[base];

int currL;
int currR;
long long curr = 0;
int cnt[N];

void inslast(int x){
	curr += cnt[sub[x]];
	++cnt[a[x]];
}

void inshead(int x){
	curr += cnt[add[x]];
	++cnt[a[x]];
}

void dellast(int x){
	curr -= cnt[sub[x]];
	--cnt[a[x]];
}

void delhead(int x){
	curr -= cnt[add[x]];
	--cnt[a[x]];
}

void fix(int l, int r){
	while(currL < l){
		int x = currL++;	
		--cnt[a[x]];
		curr -= cnt[add[x]];
	}
	while(currL > l){
	 int x = --currL;
	 	curr += cnt[add[x]];
		++cnt[a[x]];
 	}
 	while(currR < r){
 		int x = ++currR;
 		curr += cnt[sub[x]];
		++cnt[a[x]];
 	}
 	while(currR > r){
 		int x = currR--;
		 --cnt[a[x]];
 		curr -= cnt[sub[x]];
 	}
}

vector < long long > numbers;

int fin(long long x){
	return int(lower_bound(numbers.begin(), numbers.end(), x) - numbers.begin());
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d%d", &n, &k);


	for(int i = 1; i <= n; ++i){
		scanf("%d", t + i);
	}

	numbers.push_back(0);
	numbers.push_back(k);
	numbers.push_back(-k);

	for(int i = 1; i <= n; ++i){
		scanf("%lld", a + i);
		if(t[i] == 2) a[i] = -a[i];
		a[i] += a[i - 1];

		numbers.push_back(a[i]);
		numbers.push_back(a[i] + k);
		numbers.push_back(a[i] - k);
	}

	sort(numbers.begin(), numbers.end());
	numbers.resize(unique(numbers.begin(), numbers.end()) - numbers.begin());



	for(int i = 0; i <= n; ++i){
		add[i] = fin(a[i] + k);
		sub[i] = fin(a[i] - k);
		a[i] = fin(a[i]);
	}
	scanf("%d", &q);

	for(int i = 1; i <= q; ++i){
		data x;
		x.read(i);
		lst[x.u / base].push_back(x);
	}

	for(int i = 0; i < base; ++i){
		sort(lst[i].begin(), lst[i].end(), cmp);
		memset(cnt, 0, sizeof cnt);
		currL = currR =curr = 0;
		inslast(0);

		for(auto t : lst[i]){
			fix(t.u, t.v);
			ans[t.idx] = curr;
		}
	}

	for(int i = 1; i <= q; ++i){
		printf("%lld\n", ans[i]);
	}

	return 0;
}