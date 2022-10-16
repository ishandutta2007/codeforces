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
    for(int i=1;i<n;i++)
    {
        if(s[i]!=s[i-1])
        {
            printf("YES\n%c%c\n",s[i-1],s[i]);
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}