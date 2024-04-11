								/* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

#define Max 1000000

bool gr[25000010];
bool npr[Max];
vector <int> pr;

bool isprime(int x){
	int sq = (int)(sqrt((double)x) + 1e-9);
	for(int i = 2; i <= sq; i++)
		if(x % i == 0)
			return false;
	return true;
}

void find_prime(){
	for(int i = 2; i < Max; i++){
		if(!npr[i]){
			pr.push_back(i);
			for(int j = i + i; j < Max; j += i)
				npr[j] = true;
		}
	}
}

int calc(int x, int k){
	x /= k;
	if(x < k)
		return (x ? 1 : 0);
	long long res = 0;
	if(k < 80){
		int arr[30], p = 0;
		for(int i = 2; i < k; i++)
			if(isprime(i))
				arr[p++] = i;
		for(int i = 0; i < (1 << p); i++){
			long long t = 1;
			for(int j = 0; t <= x && j < p; j++)
				if(i & (1 << j))
					t *= -arr[j];
			res += x / t;
		}
	}
	else{
		for(int i = 0; i <= x; i++)
			gr[i] = false;
		for(int i = 0; pr[i] < k; i++)
			for(int j = pr[i]; j <= x; j += pr[i])
				gr[j] = true;
		for(int i = 1; i <= x; i++)
			if(!gr[i])
				res++;
	}
	return res;
}

int main(){
	int a, b, k;
	find_prime();
	while(cin >> a >> b >> k){
		if(!isprime(k)){
			cout << 0 << endl;
			continue;
		}
		cout << calc(b, k) - calc(a - 1, k) << endl;
	}
	return 0;
}