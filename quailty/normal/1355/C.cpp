#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int A,B,C,D;
    scanf("%d%d%d%d",&A,&B,&C,&D);
    ll res=0;
    for(int i=max(A+B,C+1);i<=B+C;i++)
    {
        int l=max(A,i-C),r=min(B,i-B);
        if(l<=r)res+=1LL*(r-l+1)*(min(i-1,D)-C+1);
    }
    return 0*printf("%lld\n",res);
}