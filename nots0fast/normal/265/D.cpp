#include <iostream>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;
#define fori(v) for(int i=0; i<v; i++)
#define lli long long int
#define mp make_pair
#define ff first
#define ss second
#define MAX 100011
int gcd(int a,int b)
{
    return (!b) ? a : gcd(b,a%b);
}
set<int> bolenler (int a)
{
    set<int> qaa;
    ella:
    int kok = sqrt(a);
    for(int i=2; i<=kok; i++)
    {
        if(!(a%i))
        {
            qaa.insert(i);
            a/=i;
            goto ella;
        }
    }
    qaa.insert(a);
    return qaa;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int best_case[MAX] = { };
    int n;
    cin>>n;
    fori(n)
    {
        int eded;
        cin>>eded;
        set<int> cavab = bolenler(eded);
        set<int> :: iterator it = cavab.begin();
        int maxx = 1;
        while(it!=cavab.end())
        {
            if(best_case[(*it)]+1>maxx)
            maxx = best_case[(*it)]+1;
            ++it;
        }
        it = cavab.begin();
        while(it!=cavab.end())
        {
            best_case[*it] = maxx;
            ++it;
        }
    }
    int maxx = 0;
    fori(MAX)
    maxx = max(maxx,best_case[i]);
    cout<<maxx;
}