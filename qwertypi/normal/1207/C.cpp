#include <iostream>
#include <vector>
#include <utility>
#include <numeric>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second

#define p 1000000007

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	for(int c=0;c<t;c++){
		ll n, a, b;
		cin >> n >> a >> b;
		string s;
		cin >> s;
		vector<int> cnt_0;
		int cnt_ = 1;
		char prev = '\0';
		for(int i=0;i<s.size();i++){
			if(s[i] == prev){
				cnt_++;
			}else{
				if(prev == '0'){
					cnt_0.pb(cnt_);
				}
				prev = s[i];
				cnt_ = 1;
			}
		}
		cnt_0.pb(cnt_);
		ll ans = (n + 2 * (cnt_0.size() - 1)) * a + (n * 2 + cnt_0.size() - accumulate(cnt_0.begin(), cnt_0.end(), 0LL)) * b;
		for(int i=1;i<cnt_0.size()-1;i++){
			if(2 * a >= (cnt_0[i] - 1) * b){
				ans += (cnt_0[i] - 1) * b - 2 * a;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}