#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 1e4 + 5;

struct node {
  	int to[26];
  	int num;
  	node() {
  	 	memset(to, -1, sizeof to);
  	 	num = -1;
  	}
};

char small(char c) {
 	if ('a' <= c && c <= 'z') {
 	 	return c;
 	}
 	if ('A' <= c && c <= 'Z') {
 	 	return c - 'A' + 'a';
 	}
 	assert(false);
}

int n, m;
char s[MAXN];
char word[MAXN];
vector<string> inp;
vector<node> bor;
int to[MAXN];
int by[MAXN];

int main() {
	bor.puba(node());
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d", &n);
	scanf("%s", s);

	scanf("%d", &m);

	for (int i = 0; i < m; ++i) {
	 	scanf("%s", word);
	 	int l = strlen(word);
	 	string now;
	 	int pos = 0;
	 	for (int j = 0; j < l; ++j) {
	 	 	now += word[j];
	 	 	word[j] = small(word[j]);	 	 	
	 	 	//cerr << pos << " " << word[j] << endl;
	 	 	if (bor[pos].to[word[j] - 'a'] == -1) {
	 	 	 	bor[pos].to[word[j] - 'a'] = szof(bor);
	 	 	 	bor.puba(node());
	 	 	}
			pos = bor[pos].to[word[j] - 'a'];
	 	}
	 	bor[pos].num = i;
	 	inp.puba(now);
	}

	memset(to, -1, sizeof to);
	to[0] = 0;

	for (int i = 0; i < n; ++i) {
		int pos = 0;
	 	for (int j = i; j >= 0; --j) {
	 	 	if (bor[pos].to[s[j] - 'a'] == -1) {
	 	 	 	break;
	 	 	}
	 	 	pos = bor[pos].to[s[j] - 'a'];
	 	 	//cerr << i << " " << j << " " << pos << " " << bor[pos].num << " " << to[j] << endl;
	 	 	if (bor[pos].num != -1 && to[j] != -1) {
	 	 		to[i + 1] = j;
	 	 		by[i + 1] = bor[pos].num;
	 	 		//cerr << i + 1 << " " << j << " " << bor[pos].num << endl;
	 	 		break;
	 	 	}
	 	}
	}
    
    vector<int> ans;
    for (int i = n; i > 0; i = to[i]) {
     	ans.puba(by[i]);
    }

    reverse(bend(ans));

    for (int i: ans) {
     	cout << inp[i] << " ";
    }
    cout << "\n";

	return 0;
}