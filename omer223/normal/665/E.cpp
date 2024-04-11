#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define F "BitLGM"
#define S "BitAryo"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>


using namespace std;
const int BITS_SIZE = 31;
struct trienode {
	bool c;
	int cnt, alphabet;
	trienode* sons[2];
	trienode(const bool& ch, const int& ab) : c(ch), cnt(1), alphabet(ab) { sons[0] = nullptr; sons[1] = nullptr; }
};
struct trie {
	trienode* head;
	int words, alphabet;
	char firstLetter;
	trie() : head(new trienode(0,2)), words(0), alphabet(0), firstLetter(0) { head->cnt = 1; }
	trie(int ab, char first) : head(new trienode('#', ab)), words(0), alphabet(ab), firstLetter(first) { head->cnt = 1; }
	bool insert(int num) {
		int sz = BITS_SIZE;
		trienode* iter = head;
		foru(i, 0, sz) {
			int bt = ((num >> (BITS_SIZE - 1 - i)) & 1);
			if ((iter->sons)[bt] == nullptr) {
				(iter->sons)[bt] = new trienode(bt, alphabet);
			}
			else {
				(iter->sons)[bt]->cnt++;
			}
			iter = (iter->sons)[bt];
		}
		words++;
		return true;
	}
};
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, k;

int main() {
	fast;
	cin >> n >> k;
	ll cnt = 0, tmp, crxor = 0;
	trie t(2, '0');
	t.insert(0);
	foru(i, 0, n) {
		cin >> tmp;
		crxor ^= tmp;
		trienode* iter = t.head;
		ford(j, BITS_SIZE - 1, 0) {
			switch ((k >> j) & 1) {
			case 0:
				if (iter->sons[!((crxor >> j) & 1)] != nullptr)cnt += iter->sons[!((crxor >> j) & 1)]->cnt;
				iter = iter->sons[(crxor >> j) & 1];
				break;
			case 1:
				iter = iter->sons[((crxor >> j) & 1) ^ 1];
				break;
			}
			if (iter == nullptr)break;
		}
		if (iter != nullptr)cnt += iter->cnt;
		t.insert(crxor);
	}
	cout << cnt << endl;
	return 0;
}