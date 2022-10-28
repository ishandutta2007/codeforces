
#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
int n;
int arr[N];
char c[N];
bool solve(){
	c[0] = 'G';
	c[n + 1] = 'G';
	long long res = 0;
	for(int i = 1 ; i <= n + 1 ; ++i){
		if(c[i] != 'G'){
			continue;
		}
		int j = i - 1;
		while(c[j] != 'G'){
			--j;
		}
		vector < int > reds;
		vector < int > blues;
		reds.clear();
		blues.clear();
		for(int k = j + 1 ; k < i ; ++k){
			if(c[k] == 'R'){
				reds.emplace_back(arr[k]);
			}
			else{
				blues.emplace_back(arr[k]);
			}
		}
		long long ans = 0;
		if(j != 0 && i != n + 1){
			ans += arr[i] - arr[j];
		}
		int gapred = 0;
		if(reds.size() > 0){
			if(j == 0){
				ans += arr[i] - reds[0];
			}
			else if(i == n + 1){
				ans += reds.back() - arr[j];
			}
			else{
				gapred = max(gapred , reds[0] - arr[j]);
				for(int k = 1 ; k < reds.size() ; ++k){
					gapred = max(gapred , reds[k] - reds[k - 1]);
				}
				gapred = max(gapred , arr[i] - reds.back());
				ans += arr[i] - arr[j] - gapred;
			}
		}
		int gapblue = 0;
		if(blues.size() > 0){
			if(j == 0){
				ans += arr[i] - blues[0];
			}
			else if(i == n + 1){
				ans += blues.back() - arr[j];
			}
			else{
				gapblue = max(gapblue , blues[0] - arr[j]);
				for(int k = 1 ; k < blues.size() ; ++k){
					gapblue = max(gapblue , blues[k] - blues[k - 1]);
				}
				gapblue = max(gapblue , arr[i] - blues.back());
				ans += arr[i] - arr[j] - gapblue;
			}
		}
		long long add = ans;
		if(i != n + 1 && j != 0){
			if(reds.size() && blues.size()){
				add = min(add , 2LL * (arr[i] - arr[j]));
			}
		}
		res += add;
	}
	printf("%lld\n" , res);
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		char tmp[5];
		scanf("%s" , tmp);
		c[i] = tmp[0];
	}
	bool r = 0;
	bool g = 0;
	bool b = 0;
	for(int i = 1 ; i <= n ; ++i){
		if(c[i] == 'R'){
			r = 1;
		}
		if(c[i] == 'G'){
			g = 1;
		}
		if(c[i] == 'B'){
			b = 1;
		}
	}
	if(!g){
		if(r ^ b){
			printf("%d\n" , arr[n] - arr[1]);
			return 0;
		}
		int mxred = arr[1];
		int mnred = arr[n];
		int mxblue = arr[1];
		int mnblue = arr[n];
		for(int i = 1 ; i <= n ; ++i){
			if(c[i] == 'R'){
				mxred = arr[i];
			}
			if(c[i] == 'B'){
				mxblue = arr[i];
			}
		}
		for(int i = n ; i >= 1 ; --i){
			if(c[i] == 'R'){
				mnred = arr[i];
			}
			if(c[i] == 'B'){
				mnblue = arr[i];
			}
		}
		printf("%lld\n" , 1LL * mxred - 1LL * mnred + 1LL * mxblue - 1LL * mnblue);
		return 0;
	}
	solve();
}