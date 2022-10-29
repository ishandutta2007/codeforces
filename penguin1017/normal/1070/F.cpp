#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define N (int)4e5+1
int a[2][2][N],n00,n01,n10,n11,n,v,sum01,sum10,ans,i,min1;
char op[3];
bool cmp(int a,int b)
{
    return a>b;
}
int main() {
    cin>>n;
    for(i=0;i<n;i++)
    {
        scanf("%s%d",op,&v);
        if(strcmp("00",op)==0)a[0][0][n00++]=v;
        else if(strcmp("01",op)==0)
        {
            a[0][1][n01++]=v;
            sum01+=v;
        }
        else if(strcmp("10",op)==0)
        {
            a[1][0][n10++]=v;
            sum10+=v;
        }
        else
        {
            n11++;
            ans+=v;
        }
    }
    if(n01<n10)
    {
        sort(a[1][0],a[1][0]+n10,cmp);
        ans+=sum01;
        for(i=0;i<n01;i++)
        ans+=a[1][0][i];
        for(i=n01;i<n10;i++)
        a[0][0][n00++]=a[1][0][i];
        sort(a[0][0],a[0][0]+n00,cmp);
        min1=min(n11,n00);
        for(i=0;i<min1;i++)
        ans+=a[0][0][i];
        cout<<ans;
    }
    else
    {
        sort(a[0][1],a[0][1]+n01,cmp);
        ans+=sum10;
        for(i=0;i<n10;i++)
        ans+=a[0][1][i];
        for(i=n10;i<n01;i++)
        a[0][0][n00++]=a[0][1][i];
        sort(a[0][0],a[0][0]+n00,cmp);
        min1=min(n11,n00);
        for(i=0;i<min1;i++)
        ans+=a[0][0][i];
        cout<<ans;
    }
}