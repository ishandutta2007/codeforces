#include <stdio.h>
#include <vector>

using namespace std;

vector<int> ans;

char str[10];

int ls = -1;
int n;

int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%s", str);
		int mx = 0, tmp = 1;
		for(int j = 0;str[j];j++) {
			mx *= 10;
			if(str[j] == '?') {
				mx += 9;
			}else {
				mx += str[j] - '0';
			}
			tmp *= 10;
		}
		if(mx <= ls) {
			printf("NO\n");
			return 0;
		}
		int p = tmp;
		int val = 0;
		for(int j = 0;str[j];j++) {
			p /= 10;
			if(str[j] == '?') {
				for(int x = 0;x < 10;x++) {
					if(x == 0 && j == 0) {
						continue;
					}
					int mx_val = 10 * val + x;
					for(int k = j+1;str[k];k++) {
						mx_val *= 10;
						if(str[k] == '?') {
							mx_val += 9;
						}else {
							mx_val += str[k] - '0';
						}
					}
					if(mx_val > ls) {
						val = 10 * val + x;
						break;
					}
				}
			}else {
				val = 10 * val + str[j] - '0';
			}
		}
		ans.push_back(ls = val);
	}
	printf("YES\n");
	for(int i = 0;i < n;i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}