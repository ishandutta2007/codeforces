#include <stdio.h>
#include <vector>

using namespace std;

vector<int> ans;

char str[30];
int arr[30];
int t;

void check(int a, int b) {
	for(int i = 0;i < b;i++) {
		arr[i] = 0;
	}
	for(int i = 0;i < 12;i++) {
		if(str[i] == 'X') {
			arr[i%b]++;
		}
	}
	bool err = true;
	for(int i = 0;i < b;i++) {
		if(arr[i] == a) {
			err = false;
		}
	}
	if(!err) {
		ans.push_back(a);
	}
}
int main() {
	scanf("%d", &t);
	while(t--) {
		ans.clear();
		scanf("%s", str);
		check(1, 12);
		check(2, 6);
		check(3, 4);
		check(4, 3);
		check(6, 2);
		check(12, 1);
		printf("%d ", ans.size());
		for(int i = 0;i < ans.size();i++) {
			printf("%dx%d ", ans[i], 12/ans[i]);
		}
		printf("\n");
	}
	return 0;
}