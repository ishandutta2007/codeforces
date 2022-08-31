#include <cstdio>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int a[1000007];
int b[1000007];
int c[1000007];

vector <int> wek;
int v;
int u;

int ile[1000007];

int main()
{
    srand(time(0));
    scanf("%d", &n);
    for (int i=1; i<=4*n; i++)
    {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        wek.push_back(i);
    }
    for (int i=1; i<=n; i++)
    ile[i]=4;
    printf("YES\n");
    while(!wek.empty())
    {
        v=(((long long) rand())*rand())%wek.size();
        u=wek[v];
        if (b[u]==c[u])
        {
            if (a[u]==b[u])
            {
                if (ile[a[u]]<=8)
                {
                    ile[a[u]]--;
                    ile[b[u]]++;
                    ile[c[u]]++;
                    printf("%d ", u);
                    swap(wek[v], wek.back());
                    wek.pop_back();
                }
                continue;
            }
            else
            {
                if (ile[b[u]]<=7)
                {
                    ile[a[u]]--;
                    ile[b[u]]++;
                    ile[c[u]]++;
                    printf("%d ", u);
                    swap(wek[v], wek.back());
                    wek.pop_back();
                }
                continue;
            }
        }
        else
        {
            if (a[u]==b[u])
            {
                if (ile[a[u]]<=9 && ile[c[u]]<=8)
                {
                    ile[a[u]]--;
                    ile[b[u]]++;
                    ile[c[u]]++;
                    printf("%d ", u);
                    swap(wek[v], wek.back());
                    wek.pop_back();
                }
                continue;
            }
            if (a[u]==c[u])
            {
                if (ile[a[u]]<=9 && ile[b[u]]<=8)
                {
                    ile[a[u]]--;
                    ile[b[u]]++;
                    ile[c[u]]++;
                    printf("%d ", u);
                    swap(wek[v], wek.back());
                    wek.pop_back();
                }
                continue;
            }
            if (ile[b[u]]<=8 && ile[c[u]]<=8)
            {
                ile[a[u]]--;
                ile[b[u]]++;
                ile[c[u]]++;
                printf("%d ", u);
                swap(wek[v], wek.back());
                wek.pop_back();
            }
            continue;
        }
    }
    return 0;
}