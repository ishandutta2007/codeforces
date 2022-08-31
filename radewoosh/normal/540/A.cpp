#include <cstdio>
#include <algorithm>
using namespace std;

int n;

char tab1[1007];
char tab2[1007];
int wyn;

int main()
{
    scanf("%d", &n);
    scanf("%s%s", tab1, tab2);
    for (int i=0; i<n; i++)
    {
        if (tab1[i]>tab2[i])
        {
            swap(tab1[i], tab2[i]);
        }
        wyn+=min(tab2[i]-tab1[i], tab1[i]+10-tab2[i]);
    }
    printf("%d", wyn);
    return 0;
}