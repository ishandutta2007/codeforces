#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second
typedef long long ll;
using namespace std;

string f(int sum, int left){
	if(9 * left / 2 == -sum){
		return "Bicarp";
	}else{
		return "Monocarp";
	}
}

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int not_fill[2] = {0, 0};
	int sum[2] = {0, 0};
	for(int i=0;i<n/2;i++){
		if(s[i] == '?'){
			not_fill[0]++;
		}else{
			sum[0] += s[i] - '0';
		}
	}
	for(int i=n/2;i<n;i++){
		if(s[i] == '?'){
			not_fill[1]++;
		}else{
			sum[1] += s[i] - '0';
		}
	}
	int _min = min(not_fill[0], not_fill[1]);
	not_fill[0] -= _min; not_fill[1] -= _min;
	if(not_fill[0]){
		cout << f(sum[0] - sum[1], not_fill[0]);
	}else{
		cout << f(sum[1] - sum[0], not_fill[1]);
	}
	return 0;
}