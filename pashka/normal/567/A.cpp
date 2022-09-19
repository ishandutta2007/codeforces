#include <cstdio>
#include <algorithm>
#include <vector>
 
using namespace std;

vector<int> x;


int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        x.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        int mn = (int) 2000000001;
        if (i > 0) mn = min(mn, x[i] - x[i - 1]);
        if (i < n - 1) mn = min(mn, x[i + 1] - x[i]);
        int mx = max(x[n - 1] - x[i], x[i] - x[0]);
        printf("%d %d\n", mn, mx);
    }
    return 0;
}