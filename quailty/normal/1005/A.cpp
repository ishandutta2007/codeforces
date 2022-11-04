#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    vector<int> res;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        if(a[i]>=a[i+1])
            res.push_back(a[i]);
    printf("%d\n",(int)res.size());
    for(int i=0;i<(int)res.size();i++)
        printf("%d%c",res[i]," \n"[i+1==(int)res.size()]);
    return 0;
}