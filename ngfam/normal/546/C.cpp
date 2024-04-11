#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

const int N = 20;

int ifx[N], cnt[1 << 25];

int convert(vi ver){
	int mask = 0, ans = 0;
	for(int i = 0; i < ver.size(); ++i){
		int val = ver[i] - 1;
		int calc = val - cnt[(~(-1 << (val))) & mask];
		ans += ifx[ver.size() - i - 1] * calc;
		mask |= (1 << (val));
	} 
	return ans;
}


bool done[5000000][20];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif
	
	vi start; int k1, k2, n;

	cin >> n >> k1;

	for(int i = 1; i <= k1; ++i){
		int val; cin >> val;
		start.push_back(val);
	}

	reverse(start.begin(), start.end());

	cin >> k2;

	for(int i = 1; i <= k2; ++i){
		int val; cin >> val;
		start.push_back(val);
	}

	ifx[0] = 1;

	for(int i = 1; i <= n; ++i){
		ifx[i] = ifx[i - 1] * i;
	}

	int pos = k1 - 1;

	for(int i = 1; i <= (1 << n); ++i){
		cnt[i] = cnt[i >> 1] + (i & 1);
	}

	int f = 0, g = 0;

	while(pos != -1 && pos != n - 1){
		int val1 = start[pos], val2 = start[pos + 1];

		start.erase(start.begin() + pos + 1);
		start.erase(start.begin() + pos);



		if(val1 > val2){
			start.insert(start.begin(), val2);
			start.insert(start.begin(), val1);	
			++pos;
			++f;
		}
		else{
			start.insert(start.end(), val1);
			start.insert(start.end(), val2);
			--pos;
			++g;
		}

		int idx = convert(start);
		
		pair < int, int > shift = make_pair(idx, pos);
		
		if(done[idx][pos]){
			puts("-1");
			return 0;
		}
		done[idx][pos] = 1;
	}

	cout << f + g << " " << (g > f) + 1 << endl;

	return 0;
}