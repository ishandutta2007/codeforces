#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <iostream>

inline void solve()
{
	static bool ok[11];
	memset(ok, 0, sizeof ok);
	int32_t n;
	std::cin >> n;
	std::vector<std::string> answer(n);
	std::set<std::string> used;
	for (std::string& s : answer)
	{
		std::cin >> s;
		used.insert(s);
	}
	int total = 0;
	for (int i = 0; i < n; ++i)
		if (ok[i] == false)
		{
			for (int j = i + 1; j < n; ++j)
				if (answer[i] == answer[j])
				{
					ok[j] = true;
					++total;
					for (int k = 0; k < 4; ++k)
					{
						for (char c = '0'; c <= '9'; ++c)
						{
							std::string temp = answer[j];
							temp[k] = c;
							if (used.count(temp) == 0)
							{
								used.insert(temp);
								answer[j] = temp;
								goto outside;
							}
						}
					}
					outside:
					;
				}
		}
	std::cout << total << std::endl;
	for (std::string s : answer)
		std::cout << s << std::endl;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int32_t T;
	std::cin >> T;
	while (T--)
	{
		solve();
	}
}