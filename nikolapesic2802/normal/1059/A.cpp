#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    int n,L,a;
    scanf("%i %i %i",&n,&L,&a);
    int tr=0;
    int res=0;
    for(int i=0;i<n;i++)
    {
        int l,t;
        scanf("%i %i",&l,&t);
        res+=(l-tr)/a;
        tr=l+t;
    }
    res+=(L-tr)/a;
    printf("%i\n",res);
    return 0;
}