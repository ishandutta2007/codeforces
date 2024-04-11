#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef pair < ll, ll > pll;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int ALP = 30;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int OFF = (1 << 18);

int n, k, cnt[ALP];
char s[N], t[N];

void solve(){
	scanf("%d%d %s", &n, &k, s);
	if(n % k){
		printf("-1\n");
		return;
	}
	int bar = 0;
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0;i < n;i++)
		cnt[s[i] - 'a']++;
	for(int i = 0;i < 26;i++)
		bar += (k - cnt[i] % k) % k;
	if(bar == 0){
		for(int i = 0;i < n;i++)
			printf("%c", s[i]);
		printf("\n"); return;
	}
	for(int i = n - 1;i >= 0;i--){
		bar -= (k - cnt[s[i] - 'a'] % k) % k;
		cnt[s[i] - 'a']--;
		bar += (k - cnt[s[i] - 'a'] % k) % k;
		int gdje = -1, visak = 0;		
		for(int j = s[i] - 'a' + 1;j < 26;j++){
			int ja = (k - (cnt[j] + 1) % k) % k - (k - cnt[j] % k) % k;
			if(bar + ja + 1 <= n - i){
				visak = n - i - bar - ja - 1;
				gdje = j; break;
			}
		}
		if(gdje != -1){
			t[i] = 'a' + gdje; cnt[gdje]++;
			for(int j = i + 1;j < n;j++){
				t[j] = 'a';
				if(visak > 0){
					cnt[t[j] - 'a']++;
					visak--; continue;
				}
				while(t[j] <= 'z' && cnt[t[j] - 'a'] % k == 0)
					t[j]++;
				if(t[j] > 'z') 
					t[j] = 'a';
				cnt[t[j] - 'a']++;
			}
			//for(int i = 0;i < 30;i++)
			//	if(cnt[i]) printf("cnt[ %c ] = %d\n", 'a' + i, cnt[i]);
			for(int j = 0;j < n;j++)
				printf("%c", (j < i) ? s[j] : t[j]);
			printf("\n");
			return;
		}
	}
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}