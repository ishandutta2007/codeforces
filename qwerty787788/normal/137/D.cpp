#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
//
long long k;
string s;
short poli[501][501];
short razb[501][501][501];
//
void print(long long l, long long len, long long k1) {
	if (len == 1) {
		cout << s[l-1];
		return;
	}
	if (k1 == 1) {
		string s1="";
		for (int i = l; i < l+len/2; i++)
			s1 += s[i-1];
		if (len % 2 == 1) s1 += s[l + len / 2 - 1];
		for (int i = 1; i < 1+len/2; i++)
			s1 += s[l + len/2 - i - 1];
		cout << s1;
		return;
	}
	for (int l1 = 1; l1 < len; l1++)
		if (razb[l][l1][k1 - 1]+razb[l+l1][len-l1][1] == razb[l][len][k1]) {
			print(l, l1, k1 - 1);
			cout << "+";
			print(l+l1, len-l1, 1);
			break;
		}
}
//
short min(short x, short y) {
	if (x < y) return x; else return y;
}
//
int main() {
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //
        cin >> s;
		cin >> k;
		//
		for (int i = 1; i<= s.size(); i++)
			poli[i][1] = 0;
		for (int i = 1; i< s.size(); i++)
			if (s[i-1] == s[i])
				poli[i][2] = 0; else
				poli[i][2] = 1;
		for (int len = 3; len <= s.size(); len++)
			for (int i = 1; i <= s.size() - len+1; i++)
				if (s[i-1] == s[i+len-2])
					poli[i][len] = poli[i+1][len - 2]; else
					poli[i][len] = poli[i+1][len-2]+1;
		//
		for (int start = 1; start <= s.size(); start++)
			for (int len = 1; len <= s.size()-start+1; len++)
				razb[start][len][1] = poli[start][len];
		for (int k1 = 2; k1 <= k; k1++) {
			int start = 1;
				for (int len = 1; len <= s.size()-start+1; len++) {
					short m = 1e4;
					for (int l1 = 1; l1 < len; l1++)
						m = min(m, razb[start][l1][k1 - 1]+razb[start+l1][len-l1][1]);
					razb[start][len][k1] = m;
				}
		}
		//
		short m = 1e4;
		for (int i = 1; i <= k; i++)
			m = min(m, razb[1][s.size()][i]);
		for (int i = 1; i <= k; i++)
			if (m == razb[1][s.size()][i]) {
				cout << m << endl;				
				print(1, s.size(), i);
				return 0;
			}
}