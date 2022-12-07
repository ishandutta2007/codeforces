#include <bits/stdc++.h>

using namespace std;

int cnt[300];
int now = 0;
long long n, k;


int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	cin >> n >> k;


	if(__builtin_popcountll(n) > k) {
		cout << "No";
	}
	else{
		#define f(i) cnt[i + 150]
		for(int i = 0; i <= 60; ++i){
			if(n & (1LL << i)) ++f(i), ++now;
		}

		for(int i = 60; i >= -60; --i){
			if(f(i) == 0) continue;

			if(now + f(i) <= k){
				now += f(i);
				f(i - 1) += f(i) * 2;
				f(i) = 0;
			}
			else{
				break;
			}
		}


		multiset < int > cur;
		for(int i = 60; i >= -60; --i){
			while(f(i)--) cur.insert(i);
		}

		while(cur.size() < k){
			int x = *cur.begin();
			cur.erase(cur.begin());

			cur.insert(x - 1);
			cur.insert(x - 1);
		}

		vector < int > x;
		for(auto t : cur) x.push_back(t);

			reverse(x.begin(), x.end());
		cout << "Yes" << endl;
		for(int t : x) cout << t << " ";
	}

	return 0;
}