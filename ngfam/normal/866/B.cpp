#include <bits/stdc++.h>

using namespace std;

const int N = 3e5;

struct data{
	int s;
	int a;
	int b;

	void read(){
		scanf("%d%d%d", &s, &a, &b);
	}
};

int n, s;
data a[N];
long long suf[N];

bool cmp(data u, data v){
	return u.a - u.b > v.a - v.b;
}

long long lim, tot;

long long solve(long long x){
	if(x < 0) return 0;
	if(x > (tot + s - 1) / s) return 0;

  long long y = (tot + s - 1) / s - x;
  x = x * s;
  y = y * s;


  long long ret = 0;


	for(int i = 1; i <= n; ++i){
		if(suf[i] > y){
			if(a[i].a >= a[i].b){
				long long take = min(1LL * a[i].s, x);
				ret += 1LL * a[i].a * take;
				x -= take;
				if(take < a[i].s){
					ret += 1LL * a[i].b * (a[i].s - take);
				}
			}
			else {
				long long take = min(1LL * a[i].s, suf[i] - y);
				ret += 1LL * a[i].a * take;

				if(take < a[i].s){
					ret += 1LL * a[i].b * (a[i].s - take);
				}
			}
		}
		else{
			if(a[i].a > a[i].b){
				long long take = min(1LL * a[i].s, x);
				ret += 1LL * a[i].a * take;
				x -= take;
				if(take < a[i].s){
					ret += 1LL * a[i].b * (a[i].s - take);
				}
			
			}
				else ret += 1LL * a[i].b * a[i].s;
		}
	}



	return ret;
}	

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d%d", &n, &s);

	tot = 0;


	for(int i = 1; i <= n; ++i){
		a[i].read();
		tot += a[i].s;
	}

	sort(a + 1, a + n + 1, cmp);

	for(int i = n; i >= 1; --i){
		suf[i] = suf[i + 1] + a[i].s;
	}

	long long f = 0;

	for(int i = 1; i <= n; ++i){
		if(a[i].a - a[i].b >= 0) f += a[i].s;
	}

	long long ret = max(solve(f / s), solve(f / s + 1));

	cout << ret;

	return 0;
}