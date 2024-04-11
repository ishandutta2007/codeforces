#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;

int t;
int n, k;

int m;

vector <long long> kombi[50];

vector <long long> propo;

long long mod=7340033;

void fft(vector <long long> wek)
{
    propo.clear();
    for (int i=0; i<=1002; i++)
    {
        propo.push_back(0);
        for (int j=0; j<=i; j++)
        {
            propo[i]+=wek[j]*wek[i-j];
            propo[i]%=mod;
        }
    }
}

int main()
{
    kombi[0].push_back(1);
    for (int i=1; i<=1002; i++)
    kombi[0].push_back(0);
    for (int i=1; i<=30; i++)
    {
        propo=kombi[i-1];

        fft(propo);

        fft(propo);

        for (int j=propo.size()-1; j; j--)
        {
            propo[j]=propo[j-1];
        }
        propo[0]=1;

        kombi[i]=propo;
    }
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &k);
        m=0;
        while( n>2 &&  !((n-1)&1))
        {
            m++;
            n>>=1;
        }
        if (k>=kombi[m].size())
        printf("0\n");
        else
        printf("%lld\n", kombi[m][k]);
    }
    return 0;
}