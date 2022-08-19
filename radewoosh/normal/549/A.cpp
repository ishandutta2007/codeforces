#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

char tab[100][100];

int wyn;

vector <char> wek;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++)
    {
        scanf("%s", tab[i]);
    }
    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<m-1; j++)
        {
            wek.clear();
            wek.push_back(tab[i][j]);
            wek.push_back(tab[i][j+1]);
            wek.push_back(tab[i+1][j]);
            wek.push_back(tab[i+1][j+1]);
            sort(wek.begin(), wek.end());
            if (wek[0]=='a' && wek[1]=='c' && wek[2]=='e' && wek[3]=='f')
            wyn++;
        }
    }
    printf("%d", wyn);
    return 0;
}