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
    int n,q;
    scanf("%i %i",&n,&q);
    string s;
    cin >> s;
    vector<int> pre0(n+1),pre1(n+1);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            pre0[i+1]=pre0[i]+1;
            pre1[i+1]=pre1[i];
        }
        else
        {
            pre0[i+1]=pre0[i];
            pre1[i+1]=pre1[i]+1;
        }
    }
    int powers[n+1];
    const int mod=1e9+7;
    powers[0]=1;
    int tr=2;
    for(int i=1;i<=n;i++)
    {
        powers[i]=powers[i-1];
        powers[i]=(powers[i]+tr)%mod;
        tr=(tr*2)%mod;
    }
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%i %i",&l,&r);
        int num=pre0[r]-pre0[l-1];
        int uku=r-l;
        if(num==uku+1)
        {
            printf("0\n");
            continue;
        }
        int res=powers[uku];
        if(num>0)
        res-=powers[num-1];
        if(res<0)
            res+=mod;
        printf("%i\n",res);
    }
    return 0;
}