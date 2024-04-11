#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define PB push_back

typedef long long ll;

using namespace std;

const int N = 1e4 + 500;
const int LOG = 24;
const int MSK = (1 << 24);

int n, dp[MSK];

void dinamika(){
	for(int i = 0;i < LOG;i++)
		for(int j = 0;j < MSK;j++)
			if(j & (1 << i))
				dp[j] += dp[j ^ (1 << i)];
}

int get(char c){
	return (1 << (c - 'a'));
}

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		vector < char > v;
		for(int j = 0;j < 3;j++){
			char c; scanf(" %c", &c);
			v.PB(c);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		if((int)v.size() == 1){
			dp[get(v[0])]++;
		}
		if((int)v.size() == 2){
			dp[get(v[0])]++, dp[get(v[1])]++;
			dp[get(v[0]) + get(v[1])]--;
		}
		if((int)v.size() == 3){
			dp[get(v[0])]++, dp[get(v[1])]++, dp[get(v[2])]++;
			dp[get(v[0]) + get(v[1])]--;
			dp[get(v[0]) + get(v[2])]--;
			dp[get(v[1]) + get(v[2])]--;
			dp[get(v[0]) + get(v[1]) + get(v[2])]++;		
		}
	}
	dinamika();
	ll ans = 0;
	for(int i = 0;i < MSK;i++)
		ans ^= (ll)dp[i] * dp[i];
	printf("%lld\n", ans);
	return 0;
}