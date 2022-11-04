#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
int a[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    bool isok=1;
    for(int i=1;i<n;i++)
        isok&=abs(a[i]-a[i+1])<2;
    printf("%s\n",(isok ? "YES" : "NO"));
    return 0;
}