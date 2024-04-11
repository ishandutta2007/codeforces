#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    int n,k;
    scanf("%i %i",&n,&k);
    int niz[27]={};
    string s;
    cin >> s;
    for(int i=0;i<n;i++)
    {
        niz[s[i]-'A']++;
    }
    int minn=n+1;
    for(int i=0;i<k;i++)
        minn=min(minn,niz[i]);
    printf("%i\n",minn*k);
    return 0;
}