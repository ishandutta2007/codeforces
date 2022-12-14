/**
*    author:  t0urist
*    created: 10.08.1919 11:45:14
**/

#include<bits/stdc++.h>
using namespace std;

int m;
int n;
int x;

int ask(int val){
	printf("%d\n", val);
	fflush(stdout);
	int ans;
	scanf("%d", &ans);
	if (ans == 0){
		exit(0);
	}
	return ans;
}

vector<int> query;
int main(){
	cin >> m >> n;
	for (int i = 0; i < n; i++){
		query.push_back(ask(m));
	}
	long long int cur = 0;
	int th = 0;
	for (int i = 29; i >= 0; i--){
		long long int id = cur + (1LL << (long long int)(i))-1LL;
		if (id > m)continue;
		int ret = ask(id)*query[th]*-1;
		th++;
		th %= n;
		if (ret == -1){

		}
		else{
			cur += (1LL << (long long int)(i));
		}
	}
	while (1){
		ask(cur);
		cur++;
	}
	return 0;
}