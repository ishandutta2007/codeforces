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
    string s;
    cin >> s;
    s+='z'+1;
    int rem=n-1;
    for(int i=0;i<n;i++)
    {
        if(s[i]>s[i+1])
            {
                rem=i;
                break;
            }
    }
    for(int i=0;i<n;i++)
    {
        if(rem==i)
            continue;
        printf("%c",s[i]);
    }
    return 0;
}