#include <iostream>
#include <vector>

using namespace std;

int n;
vector <pair <int,int> > a;

int obr(int i)
{
    int sum=0;
    int max=a[i].first;
    bool f=true;
    for (int j=0; j<n; j++)
    if (j!=i)
    {
        if (a[j].first>max) f=false;
        if (!f) break;
        if (a[j].second>max) sum+=a[j].second;
        else sum+=a[j].first;
    }
    sum+=a[i].second;
    int sumsum1;
    if (!f) sumsum1=1000000000;
    else sumsum1=sum*max;
    sum=0;
    max=a[i].second;
    f=true;
    for (int j=0; j<n; j++)
    if (j!=i)
    {
        if (a[j].first>max) f=false;
        if (!f) break;
        if (a[j].second>max) sum+=a[j].second;
        else sum+=a[j].first;
    }
    sum+=a[i].first;
    int sumsum2;
    if (!f) sumsum2=1000000000;
    else sumsum2=sum*max;
    return min(sumsum1,sumsum2);
}

int main()
{
    cin >>n;
    a.resize(n);
    int min=1000000000;
    for (int i=0; i<n; i++)
    {
        cin >>a[i].first >>a[i].second;
        if (a[i].first>a[i].second) swap(a[i].first,a[i].second);
    }
    for (int i=0; i<n; i++)
    {
        int x=obr(i);
        if (x<min) min=x;
    }
    cout <<min;
}