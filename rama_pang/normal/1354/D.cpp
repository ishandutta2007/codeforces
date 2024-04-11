#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const int MAXN = 1000005;
const int LOGN = 19;

int n, q;
int bit[MAXN];

void update(int x, int y) {
  for (int i = x; i < MAXN; i += i & -i) {
    bit[i] += y;
  }
}

int search(int v) {
	int sum = 0;
	int pos = 0;
	
	for(int i = LOGN; i >= 0; i--) {
		if(pos + (1 << i) < MAXN && sum + bit[pos + (1 << i)] < v) {
			sum += bit[pos + (1 << i)];
			pos += (1 << i);
		}
	}

	return pos + 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n >> q;
  int add = 0, del = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    update(a, 1);
    add++;
  }

  for (int i = 0; i < q; i++) {
    int a;
    cin >> a;
    if (1 <= a) {
      update(a, 1);
      add++;
    } else {
      int pos = search(-a);
      update(pos, -1);
      del++;
    }
  }

  if (add == del) {
    cout << 0 << "\n";
  } else {
    cout << search(1) << "\n";
  }
}