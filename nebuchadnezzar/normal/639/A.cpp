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
const int MAXN = 2e5 + 5;

int n, k, q;
int arr[MAXN];

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d%d%d", &n, &k, &q);

	for (int i = 0; i < n; ++i) {
	 	scanf("%d", arr + i);
	}

	set<int> have;

	for (int i = 0; i < q; ++i) {
     	int type, id;
     	scanf("%d%d", &type, &id);
     	--id;

     	if (type == 1) {
     	 	have.insert(arr[id]);
     	} else {
     	 	if (have.count(arr[id])) {
     	 	 	cout << "YES\n";
     	 	} else {
     	 	 	cout << "NO\n";
     	 	}
     	}
     	while (szof(have) > k) {
     	 	have.erase(have.begin());
     	}
    }

	return 0;
}