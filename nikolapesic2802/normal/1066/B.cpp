#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    int n,r;
    scanf("%i %i",&n,&r);
    vector<int> poz;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        if(a==1)
            poz.pb(i);
    }
    poz.pb(10000);
    int last=0;
    int cnt=0;
    for(int i=0;i<poz.size()-1;i++)
    {
        if(last<poz[i]-r+1)
        {
            printf("-1\n");
            return 0;
        }
        if(last<poz[i+1]-r+1&&last<n)
        {
            //printf("Uzimam poziciju %i, %i\n",i,last);
            cnt++;
            last=poz[i]+r;
        }
    }
    if(last<n)
    {
        printf("-1\n");
        return 0;
    }
    printf("%i\n",cnt);
    return 0;
}