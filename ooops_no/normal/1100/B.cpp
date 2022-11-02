/*















*/
using namespace std;
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <stack>


using namespace std;

const int N = 2e5;

int kol[N];
vector <int> g[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
		int z;
		cin >> z;
		kol[z]++;
		g[kol[z]].push_back(i);
    }
    set <int> s;
    for (int i = 1; i <= m; i++) {
		if (g[i].size() != n) break;
		s.insert(g[i][g[i].size() - 1] + 1);
    }
    for (int i = 1; i <= m; i++) {
		if (s.find(i) == s.end()) cout << 0;
		else cout << 1;
    }

}