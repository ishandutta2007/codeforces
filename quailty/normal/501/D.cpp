#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,
            rb_tree_tag,tree_order_statistics_node_update> order_set;
int in[200005],cantor[3][200005];
order_set s;
order_set::iterator itr;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&in[i]);
    s.clear();
    for(int i=n-1;i>=0;i--)
    {
        cantor[1][n-i-1]=s.order_of_key(in[i]);
        s.insert(in[i]);
    }
    for(int i=0;i<n;i++)scanf("%d",&in[i]);
    s.clear();
    for(int i=n-1;i>=0;i--)
    {
        cantor[2][n-i-1]=s.order_of_key(in[i]);
        s.insert(in[i]);
    }
    int up=0;
    for(int i=0;i<n;i++)
    {
        cantor[0][i]=(cantor[1][i]+cantor[2][i]+up)%(i+1);
        up=(cantor[1][i]+cantor[2][i]+up)/(i+1);
    }
    s.clear();
    vector<int>ans;
    for(int i=0;i<n;i++)s.insert(i);
    for(int i=n-1;i>=0;i--)
    {
        itr=s.find_by_order(cantor[0][i]);
        ans.push_back(*itr);
        s.erase(itr);
    }
    for(int i=0;i<ans.size();i++)
        printf("%s%d",(i>0 ? " " : ""),ans[i]);
    return 0;
}