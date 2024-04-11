#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,k,a,b;
    scanf("%d%d%d%d",&n,&k,&a,&b);
    int now=0;
    if(a<b)swap(a,b),now=1;
    vector<int>res;
    while(a || b)
    {
        if(!a)return 0*printf("NO");
        a--,res.push_back(now);
        for(int i=k-1;i>0 && a>b;i--)
            a--,res.push_back(now);
        swap(a,b),now^=1;
    }
    for(int i=0;i<n;i++)
        printf("%c","GB"[res[i]]);
    return 0;
}