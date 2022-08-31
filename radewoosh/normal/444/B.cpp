#include <cstdio>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

int n, d;
long long x;

int a[100007];
int b[100007];
int c[100007];
int gdzie[100007];
vector <int> wek;

int s;

long long getNextX()
{
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

void initAB()
{
    for(int i = 0; i < n; i = i + 1)
    {
        a[i] = i + 1;
    }
    for(int i = 0; i < n; i = i + 1)
    {
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(int i = 0; i < n; i = i + 1)
    {
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1)
    {
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}


int main()
{
    scanf("%d%d%lld", &n, &d, &x);
    s=min(n, 20);
    initAB();
    for (int i=n; i; i--)
    {
        a[i]=a[i-1];
        gdzie[a[i]]=i;
        b[i]=b[i-1];
    }
    for (int i=1; i<=n; i++)
    {
        if (b[i])
        {
            wek.push_back(i);
        }
        if (wek.empty())
        {
            printf("0\n");
            continue;
        }
        for (int j=n; j>=n+1-s; j--)
        {
            if (gdzie[j]<=i && b[i+1-gdzie[j]])
            {
                c[i]=j;
                break;
            }
        }
        if (c[i])
        {
            printf("%d\n", c[i]);
            continue;
        }
        for (int j=0; j<wek.size(); j++)
        {
            c[i]=max(c[i], a[i+1-wek[j]]);
        }
        printf("%d\n", c[i]);
    }
    return 0;
}