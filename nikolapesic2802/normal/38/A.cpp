#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int main()
{
    int n;
    scanf("%i",&n);
    vector<int> niz(n);
    for(int i=1;i<n;i++)
        scanf("%i",&niz[i]);
    int a,b;
    scanf("%i %i",&a,&b);
    int sum=0;
    for(int i=a;i<b;i++)
    {
        sum+=niz[i];
    }
    printf("%i\n",sum);
    return 0;
}