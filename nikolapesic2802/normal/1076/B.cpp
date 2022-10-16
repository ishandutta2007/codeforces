#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; ///find_by_order(),order_of_key()
const int N=1e6;
vector<int> primes;
vector<int> visited(N);
int main()
{
    for(int i=2;i<N;i++)
    {
        if(visited[i])
            continue;
        primes.pb(i);
        for(int j=i;j<N;j+=i)
            visited[j]=1;
        visited[i]=2;
    }
    ll n;
    scanf("%lld",&n);
    int t=(ll)sqrt(n);
    ll cnt=0;
    while(true)
    {
    for(int i=2;i<=t+1;i++)
    {
        if(n%i==0&&visited[i]==2)
        {
            if(i==2)
            {
                cnt+=(ll)n/2;
                printf("%lld\n",cnt);
                return 0;
            }
            n-=i;
            cnt++;
            break;
        }
        else
        {
            if(i==t+1)
            {
                printf("1\n");
                return 0;
            }
        }
    }
    }
    printf("1\n");
    return 0;
}