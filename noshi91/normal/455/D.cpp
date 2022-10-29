#include <iostream>
#include <algorithm>
#include <array>
#include <cstdint>
#include <climits>
#include <functional>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <utility>
#include <vector>

#define INF 1000000000
#define MOD 1000000007
#define rep(i,a,b) for(uint32 i = (a); i < (b); ++i)
#define ALL(x) (x).begin(),(x).end()
#define scanf scanf_s

using int32 = std::int_fast32_t;
using int64 = std::int_fast64_t;
using uint32 = std::uint_fast32_t;
using uint64 = std::uint_fast64_t;
#define size 317

std::vector<std::vector<uint32>> count;

int main(void) {
	std::ios::sync_with_stdio(false);
	uint32 n,b,q;
	std::cin >> n;
	std::vector<std::deque<uint32>> a(size);
	count = std::vector<std::vector<uint32>>(size, std::vector<uint32>(1 << 17, 0));
	for (uint32 i = 0;i < n;++i) {
		std::cin >> b;
		a[i / size].push_back(b);
		++count[i / size][b];
	}
	std::cin >> q;
	uint32 c, l, r, k, last = 0;
	do {
		std::cin >> c >> l >> r;
		l = (l + last - 1) % n + 1;
		r = (r + last - 1) % n + 1;
		--r;--l;
		if (l > r)std::swap(l, r);
		if (c == 1) {
			uint32 i = l / size,temp;
			temp = a[r/size][r%size];
			a[r/size].erase(a[r/size].begin() + r%size);
			--count[r/size][temp];
			a[l / size].insert(a[l / size].begin() + l%size, temp);
			++count[l / size][temp];
			while (i < r / size) {
				temp = a[i].back();
				--count[i][temp];
				a[i].pop_back();
				a[i + 1].push_front(temp);
				++i;
				++count[i][temp];
			}
		}
		else {
			std::cin >> k;
			k = (k + last - 1) % n + 1;
			last = 0;
			if (l / size == r / size) {
				for (uint32 i = l%size;i <= r%size;++i) {
					if (a[l / size][i] == k) ++last;
				}
			}
			else {
				for (uint32 i = l%size;i <size;++i) {
					if (a[l / size][i] == k) ++last;
				}
				for (uint32 i = l / size + 1;i < r / size;++i) {
					last += count[i][k];
				}
				for (uint32 i = 0;i <= r%size;++i) {
					if (a[r / size][i] == k) ++last;
				}
			}
			std::cout << last << "\n";
		}
	} while (--q);
	return 0;
}