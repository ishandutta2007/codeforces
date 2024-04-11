//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Izzz wayTn' 230u :)

typedef long long int LL;

#define sz(x) ((int)(x).size())
#define smax(x, y) (x) = max((x), (y))

struct small_array{
	vector<LL> a;
	LL max_sum, sum, presum, postsum;
	bool haspos;
	small_array(){
		haspos = false;
	}
	void PB(LL x){
		a.push_back(x);
		return;
	}
	void process(){
		max_sum = -1000000000LL * 100000000LL;
		LL s = 0;
		for(auto x : a){
			s += x;
			smax(max_sum, s);
			if(s < 0)
				s = 0;
		}
		for(int i = sz(a) - 1; i >= 0; i--){
			sum += a[i];
			smax(postsum, sum);
		}
		sum = 0;
		for(auto x : a){
			sum += x;
			smax(presum, sum);
		}
		return;
	}
} vec[51];

const int maxm = 2.5e5 + 85 - 69;
int a[maxm];
int n, m;
LL ans = -1000000000LL * 1000000000LL;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	bool haspos = false;
	for(int i = 0; i < n; i++){
		int cnt;
		cin >> cnt;
		for(int j = 0; j < cnt; j++){
			LL x;
			cin >> x;
			vec[i].PB(x);
			if(x >= 0)
				vec[i].haspos = true;
		}
		vec[i].process();
	}
	for(int i = 0; i < m; i++){
		cin >> a[i];
		a[i]--;
		smax(ans, vec[a[i]].max_sum);
		haspos |= vec[a[i]].haspos;
	}
	if(!haspos){
		cout << ans << endl;
		return 0;
	}
	LL sum = 0;
	for(int i = 0; i < m; i++){
		smax(ans, sum + vec[a[i]].presum);
		sum += vec[a[i]].sum;
		smax(sum, vec[a[i]].postsum);
	}
	cout << ans << endl;
	return 0;
}