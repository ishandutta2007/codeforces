#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    multiset<int> br1,br2;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        br1.insert(a);
    }
    for(int i=1;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        br2.insert(a);
        br1.erase(br1.find(a));
    }
    for(int i=2;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        br2.erase(br2.find(a));
    }
    printf("%i\n%i\n",*br1.begin(),*br2.begin());
    return 0;
}