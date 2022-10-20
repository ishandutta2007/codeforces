#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 100010

using namespace std;

int n, k, p, a, b, q;
vector <int> odd, even;
vector <int> kq[N];

void inkq()
{
    for(int i = 0; i < k; i++) {
        printf("%d ", (int)kq[i].size());
        for(int j = 0; j < (int)kq[i].size(); j++) printf("%d ", kq[i][j]);
        printf("\n");
    }
}

int main()
{
   //fi, fo;
    scanf("%d%d%d", &n, &k, &p);
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if(x % 2) {
            b++;
            odd.push_back(x);
        }
        else {
            a++;
            even.push_back(x);
        }
    }
    q = k - p;
    if(b < q || (b - q) % 2) {
        printf("NO");
        return 0;
    }
    if(p == 0)
    {
        for(int i = 0; i < q; i++) kq[i].push_back(odd[i]);
        for(int i = q; i < (int)odd.size(); i++) kq[q - 1].push_back(odd[i]);
        for(int i = 0; i < (int)even.size(); i++) kq[q - 1].push_back(even[i]);
        printf("YES\n");
        inkq();
        return 0;
    }
    if(a >= p) {
        printf("YES \n");
        for(int i = 0; i < p; i++)
            kq[i].push_back(even[i]);
        for(int i = p; i < (int)even.size(); i++)
            kq[p - 1].push_back(even[i]);
        for(int i = p; i < q + p; i++)
            kq[i].push_back(odd[i - p]);
        for(int i = p + q; i < (int)odd.size() + p; i++)
            kq[p - 1].push_back(odd[i - p]);
        inkq();
    }
    else {
        if(b - q < 2 * (p - a)) {
            printf("NO");
            return 0;
        }
        for(int i = 0; i < a; i++) kq[i].push_back(even[i]);
        for(int i = 0; i < q; i++) kq[i + a].push_back(odd[i]);
        int cur = q - 1;
        for(int i = 1; i <= p - a; i++) kq[i + q + a - 1].push_back(odd[++cur]), kq[i + q + a - 1].push_back(odd[++cur]);
        while(cur < (int)odd.size() - 1)
            kq[k - 1].push_back(odd[++cur]);
        printf("YES\n");
        inkq();
    }
    return 0;
}