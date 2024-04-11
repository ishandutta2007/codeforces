#include <bits/stdc++.h>

std::string E[300], T[300], F[300];
std::vector <int> EA, TA, FA;

bool cmp (const std::string &a, const std::string &b) {
	if (a.size () > b.size ()) return true;
	if (a.size () < b.size ()) return false;
	if (a > b) return true;
	return false;
}

int main () {
	std::ios::sync_with_stdio (0);
	for (int i = 0; i < 256; ++i) E[i] = T[i] = F[i] = std::string (100, '.');
	F[0x0f] = "x"; F[0x33] = "y"; F[0x55] = "z";
	EA.reserve (300); TA.reserve (300); FA.reserve (300);
	FA.push_back (0x0f); FA.push_back (0x33); FA.push_back (0x55);
	bool upd = true;
	while (upd) {
		upd = false;
		for (int i : FA) if (cmp (F[255 - i], "!" + F[i])) {
			if (F[255 - i].size () == 100) FA.push_back (255 - i);
			F[255 - i] = "!" + F[i], upd = true;
		}
		for (int i : EA) if (cmp (F[i], "(" + E[i] + ")")) {
			if (F[i].size () == 100) FA.push_back (i);
			F[i] = "(" + E[i] + ")", upd = true;
		}
		for (int i : TA) for (int j : FA) if (cmp (T[i & j], T[i] + "&" + F[j])) {
			if (T[i & j].size () == 100) TA.push_back (i & j);
			T[i & j] = T[i] + "&" + F[j], upd = true;
		}
		for (int i : FA) if (cmp (T[i], F[i])) {
			if (T[i].size () == 100) TA.push_back (i);
			T[i] = F[i], upd = true;
		}
		for (int i : EA) for (int j : TA) if (cmp (E[i | j], E[i] + "|" + T[j])) {
			if (E[i | j].size () == 100) EA.push_back (i | j);
			E[i | j] = E[i] + "|" + T[j], upd = true;
		}
		for (int i : TA) if (cmp (E[i], T[i])) {
			if (E[i].size () == 100) EA.push_back (i);
			E[i] = T[i], upd = true;
		}

	}
	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::string str;
		std::cin >> str;
		int ans = 0;
		for (int i = 0; i < 8; ++i) if (str[i] == '1') ans = ans * 2 + 1; else ans = ans * 2;
		std::cout << E[ans] << std::endl;
	}
}