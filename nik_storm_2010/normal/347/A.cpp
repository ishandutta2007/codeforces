#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector <int> a;

int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    swap(a[0], a[n - 1]);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}