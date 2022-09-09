#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

std::map<std::string, int> last;

int main() {
	int n;
	scanf("%d ", &n);
	char buf[20];
	for (int i = 0; i < n; ++i) {
		gets(buf);
		last[buf] = -i;
	}
	std::vector<std::pair<int, std::string>> all;
	for (auto& p : last) {
		all.emplace_back(p.second, p.first);
	}
	std::sort(all.begin(), all.end());
	for (auto& p : all) {
		puts(p.second.data());
	}
}