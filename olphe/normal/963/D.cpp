#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R

class K_Length_Aho_Corasick {
	struct Node {
		int index;
		vector<pair<int, int>>nx;
		int par;
		int suffixLink;
		int comp;
		Node(int id=0, int pa=0) {
			index = id, par = pa, suffixLink = 0, comp = -1;
		}
	};

	vector<Node>node;
	void WLsort() {
		for (auto &i : wl) {
			sort(i.begin(), i.end());
		}
	}
	void GlowTrie(int length) {
		int index = 0;
		for (auto i : wl[length]) {
			int cn = 0;
			for (auto j : i.first) {
				if (node[cn].nx.empty() || node[cn].nx.back().second != j) {
					index++;
					node.push_back(Node(index, cn));
					node[cn].nx.push_back({ index,j });
					cn = index;
				}
				else {
					cn = node[cn].nx.back().first;
				}
			}
			node[cn].comp = i.second;
		}
	}
	void TieSuffixLink() {
		queue<int>Q;
		Q.push(0);
		while (!Q.empty()) {
			int cn = Q.front();
			Q.pop();
			for (auto i : node[cn].nx) {
				int p = node[cn].suffixLink;
				Q.push(i.first);
				if (!cn)continue;
				while (!node[i.first].suffixLink) {
					for (auto j : node[p].nx) {
						if (j.second == i.second) {
							node[i.first].suffixLink = j.first;
						}
					}
					if (!p)break;
					p = node[p].suffixLink;
				}
			}
		}
	}

public:
	vector<vector<pair<string, int>>>wl;
	vector<vector<int>>place;
	K_Length_Aho_Corasick(vector<string>&w, int maxLength) {
		wl.resize(maxLength + 1);
		place.resize(w.size() + 1);
		for (int i = 0; i < w.size(); i++) {
			wl[w[i].size()].push_back({ w[i],i });
		}
		WLsort();
	}
	void ReConstruction_Trie(int length) {
		if (!node.empty())node.clear();
		node.push_back(Node());
		GlowTrie(length);
		TieSuffixLink();
	}
	void Search(string s) {
		int cn = 0;
		for (int i = 0; i < s.size(); i++) {
			bool flag = true;
			while (flag) {
				for (auto j : node[cn].nx) {
					if (j.second == s[i]) {
						cn = j.first;
						flag = false;
						break;
					}
				}
				if (!cn||!flag)break;
				cn = node[cn].suffixLink;
			}
			if (node[cn].comp >= 0) {
				place[node[cn].comp].push_back(i);
			}
		}
	}

	void DEBUGTrieC() {
		cerr << "Trie Size:" << node.size() << endl;
		for (auto i : node) {
			cerr << "Node " << i.index << "'s parent is " << i.par << endl;
			cerr << "Node " << i.index << "'s edges" << endl;
			for (auto j : i.nx)cerr <<"Go "<< j.first << " and charactor is " << char(j.second) << endl;
		}
	}
	void DEBUGTrieI() {
		cerr << "Trie Size:" << node.size() << endl;
		for (auto i : node) {
			cerr << "Node " << i.index << "'s parent is " << i.par << endl;
			cerr << "Node " << i.index << "'s edges" << endl;
			for (auto j : i.nx)cerr << "Go " << j.first << " and number is " << j.second << endl;
		}
	}
	void DEBUGSuffixLink() {
		for (auto i : node) {
			cerr << "Node " << i.index << "'s suffix link is " << i.suffixLink << endl;
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	cin >> N;
	vector<int>v(N);
	vector<string>w(N);
	for (int i = 0; i < N; i++)cin >> v[i] >> w[i];
	K_Length_Aho_Corasick ahocora(w, 100000);
	for (int i = 0; i <= 100000; i++) {
		if (ahocora.wl[i].empty())continue;
		//if (i == 6) {
			ahocora.ReConstruction_Trie(i);
			//ahocora.DEBUGSuffixLink();
			ahocora.Search(s);
		//}
	}
	for (int i = 0; i < N; i++) {
	//	cout << ahocora.place[i].size() << " ";
		if (ahocora.place[i].size() < v[i])cout << -1 << endl;
		else {
			int ans = ahocora.place[i][v[i] - 1] - ahocora.place[i][0];
			for (int j = 1; j + v[i] - 1 < ahocora.place[i].size(); j++) {
				ans = min(ans, ahocora.place[i][j + v[i] - 1] - ahocora.place[i][j]);
			}
			cout << ans + w[i].size() << endl;
		}
	}
	return 0;
}