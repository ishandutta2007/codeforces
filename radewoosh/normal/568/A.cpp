#include <bits/stdc++.h>
using namespace std;

long long p, q;

int sito[2000007];

int pi[2000007];
int rub[2000007];

vector <int> wek;
vector <int> por;

int czypal(int v)
{
    wek.clear();
    while(v)
    {
        wek.push_back(v%10);
        v/=10;
    }
    por=wek;
    reverse(wek.begin(), wek.end());
    if (wek==por)
    return 1;
    return 0;
}

int main()
{
    sito[1]=1;
    for (int i=2; i<=1500000; i++)
    {
        if (!sito[i])
        {
            for (int j=2*i; j<=1500000; j+=i)
            {
                sito[j]=1;
            }
        }
    }
    for (int i=1; i<=1500000; i++)
    {
        pi[i]=pi[i-1]+(!sito[i]);
        rub[i]=rub[i-1]+czypal(i);
    }
    scanf("%lld%lld", &p, &q);
    for (int i=1500000; i; i--)
    {
        if (q*pi[i]<=p*rub[i])
        {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("Palindromic tree is better than splay tree");
    return 0;
}