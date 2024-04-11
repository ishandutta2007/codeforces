#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ll l[2],r[2],k;
    for(int i=0;i<2;i++)
        scanf("%I64d%I64d",&l[i],&r[i]);
    scanf("%I64d",&k);
    ll tl=max(l[0],l[1]),tr=min(r[0],r[1]);
    printf("%I64d",max(0LL,tr-tl+1-(tl<=k && k<=tr)));
    return 0;
}