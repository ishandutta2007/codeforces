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
    vector<int> niz(n+1);
    for(int i=1;i<=n;i++)
        scanf("%i",&niz[i]);
    vector<int> razlika(n);
    for(int i=0;i<n;i++)
    {
        razlika[i]=niz[i+1]-niz[i];
        //printf("%i ",razlika[i]);
    }
    vector<int> pos;
    for(int i=1;i<n;i++)
    {
            int tr=i;
            bool test=true;
            while(tr<n)
            {
                if(razlika[tr]!=razlika[tr-i])
                {
                    test=false;
                }
                tr++;
            }
            if(test)
                pos.pb(i);
    }
    pos.pb(n);
    printf("%i\n",pos.size());
    for(auto p:pos)
        printf("%i ",p);
    printf("\n");
    return 0;
}