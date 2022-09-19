#include <cstdio>
#include <algorithm>
#include <vector>
 
using namespace std;

std::vector<int> init(1000001, 0);
std::vector<int> cur(1000001, 0);

int main()
{
    int n;
    scanf("%d", &n);
    int s = 0;
    int max = 0;
    for (int i = 0; i < n; i++) {
        char c[10];
        int r;
        scanf("%s %d", c, &r);
        if (c[0] == '+') {
            cur[r] = 1;
            s++;
            if (s > max) max = s;
        } else {
            if (!cur[r]) {
                init[r] = 1;
                s++;
                max++;
            }
            cur[r] = 0;
            s--;
        }
    }
    printf("%d\n", max);
    return 0;
}