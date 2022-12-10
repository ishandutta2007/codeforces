//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1000 * 1000 + 85 - 69;
int cnt[maxn], cnt2[maxn];
int Max;
int n;
vector<int> vec;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		cnt[x]++;
		vec.PB(x);
		smax(Max, cnt[x]);
	}
	for(int i = 0; i < n; i++){
		cnt2[vec[i]]++;
		if(cnt2[vec[i]] == Max){
			cout << vec[i] << endl;
			return 0;
		}
	}
	return 0;
}