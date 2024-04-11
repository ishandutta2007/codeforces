#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; ///find_by_order(),order_of_key()

int main()
{
    int n;
    scanf("%i",&n);
    vector<int> l(n),r(n);
    for(int i=0;i<n;i++)
    {
        scanf("%i",&l[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%i",&r[i]);
    }
    vector<pair<int,int> > sum;
    for(int i=0;i<n;i++)
    {
        sum.pb({l[i]+r[i],i});
    }
    sort(sum.begin(),sum.end());
    reverse(sum.begin(),sum.end());
    vector<int> res(n);
    int tr=0;
    for(int i=0;i<n;i++)
    {
        if(i==0||sum[i-1].first!=sum[i].first)
        {
            tr++;
        }
        res[sum[i].second]=tr;
    }
    vector<int> rl(n),rd(n);
    for(int i=0;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(res[j]>res[i])
                rl[i]++;
        }
        for(int j=i+1;j<n;j++)
        {
            if(res[j]>res[i])
                rd[i]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(rl[i]!=l[i]||rd[i]!=r[i])
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    for(int i=0;i<n;i++)
    {
        printf("%i ",res[i]);
    }
    printf("\n");
    return 0;
}