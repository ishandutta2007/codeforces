#include <bits/stdc++.h>

int occr[30], cost[30], rem;
int ans[30];

char tmp[1100000], tmp2[1100000];

int main () {
	scanf ("%s", tmp);
	int L = strlen (tmp);
	for (int i = 0; i < L; ++i)
		if (tmp[i] == '?')
			++rem;
		else
			++occr[tmp[i] - 'a'];
	scanf ("%s", tmp2);
	int L2 = strlen (tmp2);
	for (int i = 0; i < L2; ++i)
		++cost[tmp2[i] - 'a'];
	while (rem > 0) {
		for (int i = 0; i < 30; ++i)
			for (int j = 0; j < cost[i]; ++j)
				if (occr[i] > 0)
					--occr[i];
				else
					if (rem > 0) {
						--rem; ++ans[i];
					} else
						goto endloop;
endloop:;
	}
	for (int i = 0; i < L; ++i)
		if (tmp[i] == '?')
			for (int j = 0; j < 30; ++j)
				if (ans[j] > 0) {
					--ans[j];
					tmp[i] = j + 'a';
					break;
				}
	puts (tmp);
}