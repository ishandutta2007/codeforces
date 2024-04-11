#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int p;
int x, y;

int tab[1007];

int ile1, ile2;

vector <int> jed;
vector <int> dwa;

int sum;

int main()
{
    scanf("%d%d%d%d%d", &n, &k, &p, &x, &y);
    for (int i=1; i<=k; i++)
    {
        scanf("%d", &tab[i]);
        if (tab[i]>=y)
        {
            dwa.push_back(tab[i]);
            ile2++;
        }
        else
        {
            jed.push_back(tab[i]);
            ile1++;
        }
    }
    /*for (int i=0; i<jed.size(); i++)
    {
        printf("%d\n", jed[i]);
    }
    printf("\n");
    for (int i=0; i<dwa.size(); i++)
    {
        printf("%d\n", dwa[i]);
    }*/
    if (2*jed.size()+1>n)
    {
        printf("-1");
        return 0;
    }
    while(dwa.size()<=jed.size() && dwa.size()+jed.size()+1<=n)
    {
        dwa.push_back(y);
    }
    while(dwa.size()-1>jed.size() && dwa.size()+jed.size()+1<=n)
    {
        jed.push_back(1);
    }
    while(jed.size()+dwa.size()+2<=n)
    {
        jed.push_back(1);
        dwa.push_back(y);
    }
    for (int i=0; i<jed.size(); i++)
    {
        sum+=jed[i];
        //printf("%d ", jed[i]);
    }
    //printf("\n");
    for (int i=0; i<dwa.size(); i++)
    {
        sum+=dwa[i];
        //printf("%d ", dwa[i]);
    }
    //printf("\n");
    if (sum>x)
    {
        printf("-1");
        return 0;
    }
    for (int i=ile1; i<jed.size(); i++)
    {
        printf("%d ", jed[i]);
    }
    for (int i=ile2; i<dwa.size(); i++)
    {
        printf("%d ", dwa[i]);
    }
    return 0;
}