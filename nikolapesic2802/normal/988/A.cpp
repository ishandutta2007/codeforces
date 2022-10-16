#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%i %i",&n,&k);
    int pozicija[101];
    set<int> rating;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        pozicija[a]=i+1;
        rating.insert(a);
    }
    if(rating.size()>=k)
    {
        printf("YES\n");
        set<int>::iterator it;
        it=rating.begin();
        for(int i=0;i<k;i++)
        {
            printf("%i ",pozicija[*it]);
            it++;
        }
        return 0;
    }
    printf("NO\n");
    return 0;
}