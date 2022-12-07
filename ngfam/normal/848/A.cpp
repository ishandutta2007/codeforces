#include <bits/stdc++.h>

using namespace std;

long long calc(int val){
	priority_queue < int, vector < int >, greater < int > > x;
	for(int i = 1; i <= val; ++i){
		x.push(1);
	}
	long long cnt = 0;
	while(x.size() > 1){
		int u = x.top();
		x.pop();
		int v = x.top();
		x.pop();
		cnt += 1LL * u * v;
		x.push(u + v);
	}
	return cnt;
}

int  Solve(int &n){
	int low = 1, high = 100000, ans = 1;
	while(low <= high){
		int val = (low + high) >> 1;
		priority_queue < int, vector < int >, greater < int > > x;
		
		//cout << val << " " << cnt << endl;


		if(calc(val) <= n){
			ans = val;
			low = val + 1;
		}
		else{
			high = val - 1;
		}
	}
	return ans;
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	int n;
	cin >> n;

	if(n == 0){
		cout << "a";
		return 0;
	}

	for(char c = 'a'; c <= 'z'; ++c){
		int x = Solve(n);
		n -= calc(x);
		for(int i = 0; i < x; ++i){
			cout << c;
		}
	}

	return 0;
}