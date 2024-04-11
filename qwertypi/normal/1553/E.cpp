#include <bits/stdc++.h>
 
#define int long long
using namespace std;
 
int powmod(int a, int b, int p){
	int res = 1;
	while(b){
		if(b % 2){
			res = (res * a) % p;
		}
		b /= 2;
		a = (a * a) % p;
	}
	return res;
}

int p[300001];
int cnt[300001];
int q[300001];
int a[300001];
bool visited[300001];
void sub(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> p[i];
	}
	for(int i = 0; i < n; i++){
		cnt[i] = 0;
	}
	vector<int> ans;
	for(int i = 0; i < n; i++){
		cnt[((i + 1) - p[i] + n) % n]++;
	}
	
	for(int i = 0; i < n; i++){
		if(cnt[i] >= n / 3){
			for(int j = 0; j < n; j++){
				q[j] = 1 + (j - i + n) % n;
			}
			
			for(int j = 0; j < n; j++){
				visited[j + 1] = 0;
			}
//			for(int j = 0; j < n; j++){
//				cout << q[j] << ' ';
//			}
//			cout << endl;
			
			for(int j = 0; j < n; j++){
				a[q[j]] = p[j];
			}
			int cyc = 0;
			for(int j = 1; j <= n; j++){
				if(!visited[j]){
					while(!visited[j]){
						visited[j] = true;
						j = a[j];
					}
					cyc++;
				}
			}
			if(m >= n - cyc){
				ans.push_back(i);
			}
		}
	}
	cout << ans.size() << ' ';
	for(auto i : ans){
		cout << i << ' ';
	}
	cout << endl;
}


int32_t main(){
	int J;
	cin >> J;
	while(J--){
		sub();
	}
}