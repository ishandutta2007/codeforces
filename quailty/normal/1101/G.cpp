#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int a[MAXN];
vector<int> base;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),a[i]^=a[i-1];
    if(a[n]==0)return 0*printf("-1\n");
    for(int i=1;i<=n;i++)
    {
        int x=a[i];
        for(auto &t:base)
            x=min(x,x^t);
        if(x)
        {
            for(auto &t:base)
                t=min(t,x^t);
            base.push_back(x);
        }
    }
    printf("%d\n",(int)base.size());
    return 0;
}