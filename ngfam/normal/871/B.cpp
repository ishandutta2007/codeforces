#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

int n;
int f[N];
int ret[N];
int app[N];
int check[N];
int p[N];
int b[N];
int curr[N];

int ask(int x, int y){
	int ans;
	cout << "? " << x << " " << y << endl;
	cout.flush();
	cin >> ans;
	return ans;
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}	


	cin >> n;


	for(int i = 1; i < n; ++i){
		f[i] = ask(i - 1, i) ^ (check[i] = ask(i, i));
	}
	f[0] = ask(n - 1, 0) ^ (check[0] = ask(0, 0));


	int tot = 0;

	for(curr[0] = 0; curr[0] < n; ++curr[0]){
		memset(app, 0, sizeof app);

		app[curr[0]] = 1;

		bool ok = true;

		for(int i = 1; i < n; ++i){
			curr[i] = (curr[i - 1] ^ f[i]);
			if(curr[i] >= n || app[curr[i]]) {
				ok = false;
				break;
			}
			app[curr[i]] =  1;
		}
		
		if(ok == false) continue;
		
		if(curr[0] != (curr[n - 1] ^ f[0])){
			ok = false;
		}
		
		if(ok == false) continue;

		for(int i = 0; i < n; ++i){
			app[curr[i]] = i;

		}
		

		for(int i = 0; i < n; ++i){
			if((curr[i] ^ app[i]) != check[i]){
				ok = false;
				break;
			} 
		}


		if(ok){
			for(int i = 0; i < n; ++i){
				ret[i] = curr[i];
			}
			++tot;
		}
	}


	cout << "!" << endl;
	cout << tot << endl;
	for(int i = 0; i < n; ++i){
		cout << ret[i] << " ";
	}
	cout.flush();

	return 0;
}