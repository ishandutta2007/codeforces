#include <bits/stdc++.h>

int A[71000];
int cnt[1000000][10];
int flag[1000000], fc = 1;
std::map <int, int> tr1, tr2;

void print (int mask, int cnt) {
	std::string ans = std::to_string (mask);
	for (int i = ans.size (); i <= cnt; ++i)
		std::cout << '0';
	std::cout << ans << std::endl;
}

int main () {
	std::ios::sync_with_stdio (0);
	std::cin.tie (0);
	std::cout.tie (0);
	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> A[i];
		for (int mask = 10, cntt = 0; mask <= 1000000; mask *= 10, ++cntt) {
			int tmp = A[i];
			while (tmp >= mask / 10) {
				if (flag[tmp % mask] != fc) {
					++cnt[tmp % mask][cntt];
					flag[tmp % mask] = fc;
				}
				tmp /= 10;
			}
			++fc;
		}
		++tr1[A[i] / 10];
		if (A[i] / 10 != A[i] % 100000000) ++tr1[A[i] % 100000000];
		++tr2[A[i] / 100];
		if (A[i] / 100 != A[i] / 10 % 10000000) ++tr2[(A[i] / 10) % 10000000];
		if (A[i] / 100 != A[i] % 10000000 && A[i] / 10 % 10000000 != A[i] % 10000000) ++tr2[A[i] % 10000000];
	}
	for (int i = 0; i < N; ++i) {
		for (int mask = 10, cntt = 0; mask <= 1000000; mask *= 10, ++cntt) {
			int tmp = A[i];
			while (tmp >= mask / 10) {
				if (cnt[tmp % mask][cntt] == 1) {
					print (tmp % mask, cntt);
					goto next_case;
				}
				tmp /= 10;
			}
		}
		if (tr2[A[i] / 100] == 1) {
			print (A[i] / 100, 6);
		} else if (tr2[A[i] / 10 % 10000000] == 1) {
			print (A[i] / 10 % 10000000, 6);
		} else if (tr2[A[i] % 10000000] == 1) {
			print (A[i] % 10000000, 6);
		} else if (tr1[A[i] / 10] == 1) {
			print (A[i] / 10, 7);
		} else if (tr1[A[i] % 100000000] == 1) {
			print (A[i] % 100000000, 7);
		} else std::cout << A[i] << std::endl;
next_case:;
	}
}