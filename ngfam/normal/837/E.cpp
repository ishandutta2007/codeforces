#include <bits/stdc++.h>

using namespace std;

long long x, y;

long long lcm(long long x, long long y){
	return (x / __gcd(x, y)) * y;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
	#endif
	cin >> x >> y;
	vector < long long  > dvs;
	for(long long i = 1; i * i <= x; ++i){
		if(x % i == 0){
			dvs.push_back(i);
			if(i * i != x){
				dvs.push_back(x / i);
			}
		}
	}
	long long answer = 0;
	sort(dvs.begin(), dvs.end());
	long long curr = __gcd(x, y);
	while(y > 0){
		int pter = 0;
		while(pter < dvs.size() && dvs[pter] < curr){
			++pter;
		}
		long long best = 0;
		long long calc = 1e13;
		for(int i = pter + 1; i < dvs.size(); ++i){
			if(dvs[i] % curr != 0){
				continue;
			}
			long long modun = y % dvs[i];
			if(modun % curr != 0){
				continue;
			}
			if(calc > (modun / curr)){
				calc = modun / curr;
				best = dvs[i];
			}
		}
	//	cout << best << " " << curr << " " << calc << endl;
		if(best != 0){
			answer += calc;
			y -= calc * curr;
			curr = best;
			
		}
		else{
			answer += y / curr;
			y = 0;
		}
		//cout << y << endl;
		//break;
	}
	cout << answer;
	return 0;
}