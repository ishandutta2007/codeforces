#include <cstdio>
#include <algorithm>
using std::min;

int main() {
	for (int id = 21; id <= 50; ++id)
		printf("%d\n", ((min(25, id) + id) % (2 + id % 3)) > 0);
	return 0;
}