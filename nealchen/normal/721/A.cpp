#include <stdio.h>
#include <vector>
std::vector<int> a;
int main() {
	int n, t = 0;
	char s[233];
	scanf("%d%s", &n, s);
	for(register int i = 0; i <= n; ++i) {
		if(s[i] != 'B' && i && s[i - 1] == 'B') a.push_back(t), t = 0;
		if(s[i] == 'B') ++t;
	}
	printf("%d\n", a.size());
	for(register int i = 0; i < a.size(); ++i) printf("%d ", a[i]);
	return 0;
}