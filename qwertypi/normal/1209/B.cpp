#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second

using namespace std;

typedef long long ll;

bool init[100];
int data[100][2];
int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i=0;i<n;i++){
		cin >> data[i][0] >> data[i][1];
	}
	for(int i=0;i<n;i++){
		init[i] = s[i] - '0';
	}
	int ans = accumulate(init, init+n, 0);
	for(int i=1;i<=240;i++){
		int cnt = 0;
		for(int j=0;j<n;j++){
			if(i < data[j][1]){
				cnt += init[j];
			}else{
				cnt += init[j] ^ (((i - data[j][1]) / data[j][0] + 1) % 2);
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}