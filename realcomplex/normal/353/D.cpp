#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = (int)1e6;
int dp[N];

int main(){
	fastIO;
	string s;
	cin >> s;
	int n = s.size();
	vector<int> ff;
	for(int i = 0; i < n;i ++ ){
		if(s[i] == 'F')	
			ff.push_back(i);
	}
	if(ff.empty()){
		cout << 0;
		return 0;
	}
	dp[0] = ff[0];
	for(int i = 1; i < ff.size(); i ++ ){
		if(i == ff[i])
			dp[i] = 0;
		else
			dp[i] = max(dp[i - 1] + 1, ff[i] - i);
	}
	cout <<dp[ff.size() - 1];
	return 0;
}