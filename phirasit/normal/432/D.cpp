#include <stdio.h>
#include <string.h>
#include <vector>

#define N 100010

using namespace std;

vector<int> ans;
char str[N];
int cnt[N];
int Z[N];
int T[N], l;

int main() {
	
	scanf("%s", str+1);
	l = strlen(str+1);

	ans.push_back(l);

	cnt[1] = 1;
	cnt[l+1] = -1;

	Z[1] = 0;
	int mx = 1;
	for(int i = 2;i <= l;i++) {
		Z[i] = mx + Z[mx] - 1 >= i ? min(Z[i - mx + 1], mx + Z[mx] - i) : 0;
		if(i + Z[i] - 1 > l) Z[i] = l - i + 1; 
		while(str[i + Z[i]] == str[Z[i] + 1]) {
			Z[i]++;
		}
		if(i + Z[i] > mx + Z[mx]) {
			mx = i;
		}
		if(i + Z[i] - 1 == l) {
			ans.push_back(Z[i]);
		}
		cnt[1]++;
		cnt[Z[i] + 1]--;
	}
	for(int i = 2;i <= l;i++) {
		cnt[i] += cnt[i-1];
	}
	
	printf("%d\n", (int)ans.size());
	for(int i = (int)ans.size() - 1;i >= 0;i--) {
		printf("%d %d\n", ans[i], cnt[ans[i]]);
	}
	return 0;
}