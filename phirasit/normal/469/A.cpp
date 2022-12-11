#include <stdio.h>
#include <set>

using namespace std;

int n, x, y, lv;

int main() {
	set<int> S;
	scanf("%d", &n);
	scanf("%d", &x);
	for(int i = 0;i < x;i++) {
		scanf("%d", &lv);
		S.insert(lv);
	}
	scanf("%d", &y);
	for(int i = 0;i < y;i++) {
		scanf("%d", &lv);
		S.insert(lv);
	}
	if(S.size() == n) {
		printf("I become the guy.\n");
	}else {
		printf("Oh, my keyboard!\n");
	}
	return 0;
}