#include <bits/stdc++.h>
#define ll long long
using namespace std;
char c;
int n,m,h1,h2,poz=-1,i;
int main()
{
    scanf("%i %i",&n,&m);
    if(n-1>m)
    {
        printf("NO\n");
        return 0;
    }
    for(i=0; i<n; i++)
    {
        scanf(" %c",&c);
        if(c=='*')
        {
            poz=i;
            break;
        }
        //printf("%i %i\n",h1,c);
        h1=(h1*28+c-'a'+1)%10000007;
        //printf("%i\n",h1);
    }
    if(poz==-1&&n!=m)
    {
        printf("NO\n");
        return 0;
    }
    if(poz!=-1)
    for(i=poz+1; i<n; i++)
    {
        scanf("%c ",&c);
        h1=((ll)h1*(ll)(28)+c-'a'+1)%10000007;
    }
    //printf("%i\n",h1);
    for(i=0; i<poz; i++)
    {
        scanf(" %c",&c);
        h2=((ll)h2*(ll)(28)+c-'a'+1)%10000007;
    }
    for(i=i; i<=m-n+poz; i++)
        scanf("%c",&c);
    for(i=m-n+poz+1; i<m; i++)
    {
        scanf(" %c",&c);
        h2=((ll)h2*(28)+c-'a'+1)%10000007;
    }
    if(h1!=h2)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}