#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef double db;
typedef long long ll;
const int MAXN=200005;
map<int,int>mp;
int b[MAXN],c[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        mp[a]++;
    }
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&c[i]);
    int loc=1;
    for(int i=1;i<=m;i++)
        if(mp[b[i]]>mp[b[loc]] || (mp[b[i]]==mp[b[loc]] && mp[c[i]]>mp[c[loc]]))loc=i;
    printf("%d\n",loc);
    return 0;
}