#include <bits/stdc++.h>
#define int long long
using namespace std;

int A[100000];

int lp[200000+1];
vector<int> pr;

int gcd(int a, int b){
	while(b){
		a %= b;
		swap(a, b);
	}
	return a;
}

int lcm(int a, int b){
	return a * b / gcd(a, b);
}

int cnt[200001];
int32_t main(){
	int n;
	cin >> n;
	for (int i = 2; i <= 200000; i++){
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.push_back(i);
	    }
	    for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= 200000; j++){
	    	lp[i * pr[j]] = pr[j];
		}
	}
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	int g = 0;
	for(int i = 0; i < n; i++){
		g = gcd(g, A[i]);
	}
	for(int i = 0; i < n; i++){
		A[i] /= g;
	}
	for(int i = 0; i < n; i++){
		int x = A[i];
		map<int, int> M;
		while(x != 1){
			M[lp[x]]++;
			x /= lp[x];
		}
		for(auto i : M){
			for(int j = 1; j <= i.second; j++){
				cnt[(int) pow(i.first, j)]++;
			}
		}
	}
	int ans = 1;
	for(int i : pr){
		int x = i;
		while(x <= 200000 && cnt[x] == n - 1){
			ans *= i;
			x *= i;
		}
	}
	cout << ans * g << endl;
	return 0;
}