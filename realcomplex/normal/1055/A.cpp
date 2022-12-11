#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void answer(bool ok){
	if(ok == true)
		cout << "YES\n";
	else
		cout << "NO\n";
	exit(0);
}

int main(){
	fastIO;
	int n, s;
	cin >> n >> s;
	-- s;
	int a[n];
	int b[n];
	for(int i = 0; i < n; i ++ ){
		cin >> a[i];
	}
	for(int i = 0 ; i < n ; i++ ){
		cin >> b[i];
	}
	if(a[0] == 0)
		answer(false);
	if(a[s])
		answer(true);
	if(b[s] ==  0)
		answer(false);
	for(int i = 0 ; i < n; i ++ ){
		if(a[i] & b[i]){
			if(i >= s)
				answer(true);
		}
	}
	answer(false);
	return 0;
}