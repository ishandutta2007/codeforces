#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    vector<int> niz;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        niz.push_back(a);
    }
    sort(niz.begin(),niz.end());
    /*for(int i=0;i<n;i++)
    {
        printf("%i ",niz[i]);
    }
    printf("\n");*/
    printf("%i",niz[(niz.size()-0.5)/2]);
    return 0;
}