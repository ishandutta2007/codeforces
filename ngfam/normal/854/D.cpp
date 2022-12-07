#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;

struct Flight{
	int d;
	int f;
	int t;
	int c;

	void read(){
		scanf("%d%d%d%lld", &d, &f, &t, &c);
	}
};

int n, k, m;

long long f[N];
long long t[N];
int current[N];

vector < Flight > At[N];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d%d%d", &n, &m, &k);

	for(int i = 1; i <= m; ++i){
		Flight x;
		x.read();

		At[x.d].push_back(x);
	}

	memset(current, 60, sizeof current);
	for(int i = 1; i <= n; ++i){
		f[1000001] += current[i];
	}

	for(int d = 1000000; d >= 1; --d){
		
		f[d] = f[d + 1];	

		for(int i = 0; i < At[d].size(); ++i){
			Flight x = At[d][i];

			if(x.f == 0){
				long long old = current[x.t];
				current[x.t] = min(current[x.t], x.c);
				f[d] = f[d] + current[x.t] - old;
			}
		}
	}

	memset(current, 60, sizeof current);
	for(int i = 1; i <= n; ++i){
		t[0] += current[i];
	}


	for(int d = 1; d <= 1000000; ++d){
		t[d] = t[d - 1];

		for(int i = 0; i < At[d].size(); ++i){
			Flight x = At[d][i];

			if(x.f != 0){
				long long old = current[x.f];
				current[x.f] = min(current[x.f], x.c);
				t[d] = t[d] + current[x.f] - old;
			}
		}
	}

	long long ans = 1e18;

	for(int i = k + 1; i <= 999999; ++i){
		ans = min(ans, t[i - k] + f[i + 1]);
	}

	if(ans > 2LL * n * 1000000LL){
		ans = -1;
	}

	cout << ans;

	return 0;
}