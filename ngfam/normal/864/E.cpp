#include <bits/stdc++.h>

using namespace std;

const int N = 110;
const int M = 2020;

struct Item{
	int t;
	int d;
	int p;
	int idx;

	void read(int i){
		scanf("%d%d%d", &t, &d, &p);
		idx = i;
	}
}a[N];

bool cmp(Item u, Item v){
	return u.d > v.d;
}

bool cmax(int &u, int v){
	if(u < v){
		u = v;
		return 1;
	}
	return 0;
}

int n;
int f[N][M];
int pr[N][M];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		a[i].read(i);
	}

	sort(a + 1, a + n + 1, cmp);

	int last = 0;

	for(int i = 1; i <= n; ++i){
		for(int t = 2002; t >= 1; --t){
			if(cmax(f[i][t], f[i - 1][t])){
				pr[i][t] = 0;
			}
			if(t > a[i].t && t <= a[i].d){
				if(cmax(f[i][t - a[i].t], f[i - 1][t] + a[i].p)){
					pr[i][t - a[i].t] = t;
				}
			}	
			if(i == n && f[n][t] >= f[n][last]) last = t;
		}
	}

	cout << f[n][last] << endl;
	vector < int > ans;

	for(int i = n; i >= 1; --i){
		if(pr[i][last] > 0) ans.push_back(a[i].idx), last = pr[i][last];
	}


	cout << ans.size() << endl;
	for(int x : ans) cout << x << " " ;

	return 0;
}