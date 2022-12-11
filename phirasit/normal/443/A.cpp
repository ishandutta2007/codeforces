#include <stdio.h>
#include <set>

using namespace std;

int main() {
	set<char> S;
	char ch;
	while(scanf("%c", &ch) != EOF) {
		if('a' <= ch && ch <= 'z') {
			S.insert(ch);
		}
	}
	printf("%d\n", S.size());
	return 0;
}