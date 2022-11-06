#include<bits/stdc++.h>
using namespace std;
int get(string t)
{
    if(t=="S")return 0;
    if(t=="XS")return 1;
    if(t=="XXS")return 2;
    if(t=="XXXS")return 3;
    if(t=="M")return 4;
    if(t=="L")return 5;
    if(t=="XL")return 6;
    if(t=="XXL")return 7;
    if(t=="XXXL")return 8;
    return -1;
}
int main()
{
    int n,p[9]={0};
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string t;
        cin>>t;
        p[get(t)]++;
    }
    for(int i=1;i<=n;i++)
    {
        string t;
        cin>>t;
        p[get(t)]--;
    }
    int res=0;
    for(int i=0;i<9;i++)
        res+=abs(p[i]);
    printf("%d\n",res/2);
    return 0;
}