#include <stdio.h>
#include <vector>

using namespace std;

vector<int> ans;

int a, b;
int n, k;

int main() {
	scanf("%d%d", &n, &k);
	a = 2, b = n;
	ans.push_back(1);
	for(int i = 0;i < k-1;i++) {
		if(i%2) {
			ans.push_back(a++);
		}else {
			ans.push_back(b--);
		}
	}
	if(ans[ans.size()-1] == a-1) {
		for(int i = a;i <= b;i++) {
			ans.push_back(i);
		}
	}else {
		for(int i = b;i >= a;i--) {
			ans.push_back(i);
		}
	}
	for(int i = 0;i < ans.size();i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}