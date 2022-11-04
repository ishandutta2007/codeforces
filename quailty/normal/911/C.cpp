#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll k[3];
    for(int i=0;i<3;i++)
        scanf("%lld",&k[i]);
    sort(k,k+3);
    if(k[0]==1)printf("YES\n");
    else if(k[0]==2 && k[1]==2)printf("YES\n");
    else if(k[0]==2 && k[1]==4 && k[2]==4)printf("YES\n");
    else if(k[0]==3 && k[1]==3 && k[2]==3)printf("YES\n");
    else printf("NO\n");
    return 0;
}