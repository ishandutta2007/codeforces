#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int a[MAXN],b[MAXN],id[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
        id[i]=i;
    sort(id+1,id+n+1,[](int x,int y){return a[x]>a[y];});
    printf("%d\n%d",n/2+1,id[1]);
    for(int i=2;i<n;i+=2)
        printf(" %d",id[i+(b[id[i]]<b[id[i+1]])]);
    if(n%2==0)printf(" %d",id[n]);
    return 0;
}