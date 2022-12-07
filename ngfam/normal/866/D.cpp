#include <bits/stdc++.h>

using namespace std;

const int N = 305000;

multiset < int > pl;
multiset < int > mn;
multiset < int > unused;

int n;
int a[N];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d", &n);

	long long ans = 0;

	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);

		if(!unused.empty()){

			int f = *unused.begin();


			if(x > f)
			if(!pl.empty() && f > *pl.begin()){}
			else{
				pl.insert(x);
				mn.insert(f);
				ans += x - f;
				unused.erase(unused.begin());
				continue;
			}
		}

		if(!pl.empty() && x > *pl.begin()){
			ans += x - *pl.begin();
			pl.insert(x);
			unused.insert(*pl.begin());
			pl.erase(pl.begin());
		}
		else{
			unused.insert(x);
		}
	}

	cout << ans;

	return 0;
}