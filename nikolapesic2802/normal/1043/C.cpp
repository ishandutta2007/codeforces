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
    string s;
    cin >> s;
    int n=s.size();
    s+='b';
    int l=0,r=0;
    vector<int> res(n);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a')
        {
            if(s[i+1]=='b'){
                res[i]=1;
            }
        }
        else
        {
            if(s[i+1]=='a')
                res[i]=1;
        }
    }
    for(auto p:res)
    {
        printf("%i ",p);
    }
    printf("\n");
    return 0;
}