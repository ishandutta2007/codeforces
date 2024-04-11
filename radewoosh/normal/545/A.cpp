#include <cstdio>
#include <vector>
using namespace std;

int n;
vector <int> wyn;

int a;
int czy;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        czy=1;
        for (int j=1; j<=n; j++)
        {
            scanf("%d", &a);
            if (a==1 || a==3)
            {
                czy=0;
            }
        }
        if (czy)
        {
            wyn.push_back(i);
        }
    }
    printf("%d\n", wyn.size());
    for (int i=0; i<wyn.size(); i++)
    {
        printf("%d ", wyn[i]);
    }
    return 0;
}