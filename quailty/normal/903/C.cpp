#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    map<int,int> mp;
    for(int i=1,a;i<=n;i++)
        scanf("%d",&a),mp[a]++;
    int res=0;
    for(auto t:mp)
        res=max(res,t.second);
    printf("%d\n",res);
    return 0;
}