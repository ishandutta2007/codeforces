#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    vector<int> niz(n);
    for(int i=0;i<n;i++)
        scanf("%i",&niz[i]);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=niz[j];
            if((double)sum/(j-i+1)>(double)100)
            {
                cnt=max(cnt,j-i+1);
            }
        }
    }
    printf("%i",cnt);
    return 0;
}