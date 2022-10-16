#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    int n,m;
    scanf("%i %i",&n,&m);
    int sum=m;
    int maxx=0;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        sum+=a;
        maxx=max(maxx,a);
    }
    int maxxxx=sum/n;
    if(sum%n!=0)
        maxxxx++;
    printf("%i %i\n",max(maxxxx,maxx),maxx+m);
    return 0;
}