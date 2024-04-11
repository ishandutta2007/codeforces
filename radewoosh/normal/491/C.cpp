#include <bits/stdc++.h>
using namespace std;

/* HUNGARIAN O(n^3)                                                           */
/* maksymalne najdrozsze skojarzenie w pelnym grafie dwudzielnym o            */
/* rownolicznych zbiorach wierzcholkow, argumenty to macierz z wagami         */
/* i liczba wierzcholkow, zwracany wynik to wektor ktory mowi co jest z czym  */
/* skojarzone.                                                                */
/* Jak chcemy najtansze to bierzemy wszystko z minusem, jak gdzies nie ma     */
/* krawedzi to dajemy -INF, przy zalozeniu, ze: n * |waga| < INF              */

vector <int> hungarian(vector < vector <int> > w, int n)
{
    int lx[n],ly[n],skojx[n],skojy[n];
    int markx[n],marky[n],slack[n],par[n],q[n];
    for (int i=0; i<n; i++)
    {
        skojx[i]=skojy[i]=-1;
        ly[i]=0;
        lx[i]=*max_element(w[i].begin(), w[i].end());
    }
    for (int k=0; k<n; k++)
    {
        int v=-1,qb=0,qe=0;
        for (int i=0; i<n; i++)
        {
            marky[i]=markx[i]=0;
            slack[i]=-1;
            if (skojx[i]==-1)
				q[qe++]=i;
        }
        while (v==-1)
        {
            while (qb<qe)
            {
                int i=q[qb++];
                markx[i]=1;
                for (int j=0; j<n; j++)
					if (!marky[j] && (slack[j]==-1 || slack[j]>lx[i]+ly[j]-w[i][j]))
					{
						if ((slack[j] = lx[ par[j]=i ]+ly[j]-w[i][j]) == 0)
						{
							marky[j]=1;
							if (skojy[j]!=-1)
								q[qe++]=skojy[j];
							else
							{
								v=j;
								goto koniec;
							}
						}
					}
            }
            int x=-1;
            for (int i=0; i<n; i++)
				if (!marky[i] && (x==-1 || slack[i] < x))
					x=slack[i];
            for (int i=0; i<n; i++)
            {
                if (markx[i])
					lx[i]-=x;
                if (marky[i])
					ly[i]+=x;
                else
					if ((slack[i] -= x) == 0)
					{
						marky[i]=1;
						if (skojy[i] != -1)
							q[qe++]=skojy[i];
						else
							v=i;
					}
            }
        }
        koniec:
        while (v!=-1)
        {
            int y=skojx[par[v]];
            skojx[par[v]]=v;
            skojy[v]=par[v];
            v=y;
        }
    }
    return vector <int> (skojx,skojx+n);
}

int n, k;

int num[1007];
char jak[1007];

vector < vector <int> > tab;
vector < vector <int> > daj;

vector <int> sko;
int wyn;

char wcz1[2000007];
char wcz2[2000007];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i='a'; i<='z'; i++)
	{
		num[i]=i-'a';
		jak[num[i]]=i;
	}
	for (int i='A'; i<='Z'; i++)
	{
		num[i]=i-'A'+26;
		jak[num[i]]=i;
	}
	tab.push_back(vector <int>{});
	for (int i=0; i<k; i++)
		tab[0].push_back(0);
	for (int i=1; i<k; i++)
		tab.push_back(tab[0]);
	scanf("%s%s", wcz1+1, wcz2+1);
	for (int i=1; i<=n; i++)
		tab[num[wcz1[i]]][num[wcz2[i]]]++;
	daj=tab;
	sko=hungarian(daj, k);
	for (int i=0; i<k; i++)
		wyn+=tab[i][sko[i]];
	printf("%d\n", wyn);
	for (int i=0; i<k; i++)
		printf("%c", jak[sko[i]]);
	printf("\n");
	return 0;
}