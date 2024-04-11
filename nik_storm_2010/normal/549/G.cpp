#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <bitset>
#include <fstream>
#include <stack>
#include <deque>
#include <utility>
#include <numeric>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 200000 + 100;

int a[N];
priority_queue<int> q;
vector<int> ans;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; i++) {
        a[i] -= n - i;
        q.push(a[i]);
    }
    
    int add = 0;
    for (int i = 1; i <= n; i++) {
        int cur = q.top();
        q.pop();
        ans.push_back(cur + add);
        add++;
    }
    
    reverse(ans.begin(), ans.end());
    
    for (int i = 0; i < n; i++) {
        if (ans[i] < 0) {
            printf(":(\n");
            return 0;
        }
        if (i + 1 != n && ans[i] > ans[i + 1]) {
            printf(":(\n");
            return 0;
        }
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}