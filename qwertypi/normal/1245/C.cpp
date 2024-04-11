#include <bits/stdc++.h>
#define m 1000000007
using namespace std;

long long ans = 1;

long long F[100001];

void f(int x){
	ans = (ans * F[x]) % m;
}

int main(){
	F[0] = 1;
	F[1] = 1;
	for(int i = 2; i < 100001; i++){
		F[i] = (F[i-2] + F[i-1]) % m;
	}
	string s;
	cin >> s;
	char c = '\0';
	int cnt = 0;
	for(auto i : s){
		if(i == 'm' || i == 'w'){
			cout << 0;
			return 0;
		}
		if(c == i){
			cnt++;
		}else{
			if(c == 'u' || c == 'n')
				f(cnt);
			cnt = 1;
			c = i;
		}
	}
	if(c == 'u' || c == 'n')
		f(cnt);
	cout << ans;
}