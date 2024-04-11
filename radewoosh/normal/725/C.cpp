#include <bits/stdc++.h>
using namespace std;

string wcz;

int ile[1007];

char co[10007];

string now;

int k;

int l;

char wyn[2][28];

char nast()
{
    if (!l)
    {
        l=1;
        return now[0];
    }
    if (now[l]==now[0])
        l++;
    l++;
    return now[l-1];
}

int main()
{
    cin >> wcz;
    for (int i=0; i<27; i++)
        ile[wcz[i]]++;
    for (int i=0; i<27; i++)
    {
        if (ile[wcz[i]]==2)
        {
            for (int j=i; j<27; j++)
                now.push_back(wcz[j]);
            for (int j=0; j<i; j++)
                now.push_back(wcz[j]);
            break;
        }
    }
    for (int i=1; i<27; i++)
        if (now[i]==now[0])
            k=i;
    if (k==1)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    k-=1;
    k/=2;
    for (int i=k; i>=0; i--)
        wyn[0][i]=nast();
    for (int i=0; i<13; i++)
        wyn[1][i]=nast();
    for (int i=12; i>k; i--)
        wyn[0][i]=nast();
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<13; j++)
            cout << wyn[i][j];
        cout << endl;
    }
    return 0;
}