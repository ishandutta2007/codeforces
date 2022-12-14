#include<iostream>
#include<cstdio>
#include<set>
#include<random>
#include<ctime>
#include<bits/stdc++.h>
using namespace std;

mt19937 rnd(time(NULL));
mt19937_64 rnd64(time(NULL));

const int MAX = 1000002;

int t;

int k;

char s[1000002];
char A[1000002];
char B[1000002];

char fi[26];
int len;

bool calc(char *mp2) {
	char used[26];
	char mp[26];
	for (int i = 0; i < k; i++)mp[i] = mp2[i];
	memset(used, false, sizeof(used));
	for (int i = 0; i < k; i++) {
		if (mp[i])used[mp[i] - 'a'] = true;
	}
	int pos = k - 1;
	while (pos >= 0 && used[pos])pos--;
	for (int i = 0; i < len; i++) {
		if (mp[s[i] - 'a']) {
			if (mp[s[i] - 'a'] < A[i])return false;
			if (mp[s[i] - 'a'] == A[i])continue;
			for (int i = 0; i < k; i++)fi[i] = mp[i];
			return true;
		}
		if (pos + 'a' < A[i])return false;
		if (pos + 'a' == A[i]) {
			mp[s[i] - 'a'] = pos + 'a';
			used[pos] = true;
			while (pos >= 0 && used[pos])pos--;
			continue;
		}
		mp[s[i] - 'a'] = pos + 'a';
		for (int i = 0; i < k; i++)fi[i] = mp[i];
		return true;
	}
	for (int i = 0; i < k; i++)fi[i] = mp[i];
	return true;
}
string f1;
string f2;
int main() {
	cin >> t;
	while (t--) {
		scanf("%d",&k);
		scanf("%s", s);
		scanf("%s", A);
		scanf("%s", B);
		f1 = A;
		f2 = B;
		len = strlen(s);
		char mp[26];
		memset(mp, 0, sizeof(mp));
		bool used[26];
		memset(used, false, sizeof(used));
		if (f1 > f2) {
			puts("NO");
			continue;
		}
		bool made = false;
		for (int i = 0; i <= len; i++) {
			if (i == len) {
				made = true;
				break;
			}
			if (mp[s[i] - 'a'] && mp[s[i] - 'a'] == B[i])continue;
			if (mp[s[i] - 'a'] && mp[s[i] - 'a'] > B[i]) {
				break;
			}
			if (mp[s[i] - 'a']) {
				if (calc(mp)) {
					made = true;
					for (int i = 0; i < k; i++)mp[i] = fi[i];
					break;
				}
			}
			else {
				for (int z = B[i]-1; z >='a'; z--) {
					if (used[z - 'a'])continue;
					mp[s[i] - 'a'] = z;
					if (calc(mp)) {
						made = true;
						for (int i = 0; i < k; i++)mp[i] = fi[i];
						break;
					}
					mp[s[i] - 'a'] = 0;
					break;
				}
			}
			if (made)break;
			if (mp[s[i] - 'a']) {
				break;
			}
			else {
				if (used[B[i] - 'a'] == false) {
					used[B[i] - 'a'] = true;
					mp[s[i] - 'a'] = B[i];
				}
				else {
					break;
				}
			}
		}
		if (made == false) {
			puts("NO");
			continue;
		}
		puts("YES");
		int pos = k - 1;
		for (int i = 0; i < k; i++) {
			if(mp[i])used[mp[i]-'a'] = true;
		}
		while (pos >= 0 && used[pos])pos--;
		for (char z = 0; z < k; z++) {
			if (mp[z] == 0) {
				mp[z] = pos+'a';
				used[pos] = true;
				while (pos >= 0 && used[pos])pos--;
			}
		}
		string ret;
		for (int i = 0; i < k; i++) {
			ret.push_back(mp[i]);
		}
		printf("%s\n", ret.c_str());
	}
	return 0;
}