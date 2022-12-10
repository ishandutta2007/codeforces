//??? mizanam ghorbatan elallah :D
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Izzz wayTn' 230u :)

const int maxn = 1e5 + 10;
int a[maxn], n;

bool isgood(int len){
	bool ret = false;
	for(int i = 0; i < len; i++){
		bool an = a[i];
		for(int j = (i + len) % n; j != i; j = (j + len) % n)
			an &= a[j];
		ret |= an;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int len = 1; len * len <= n; len++)
		if(n % len == 0 and ((n / len >= 3 and isgood(len)) or (len >= 3 and isgood(n / len)))){
			cout << "YES" << endl;
			return 0;
		}
	cout << "NO" << endl;
	return 0;
}