#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int main()
{
    int n;
    scanf("%i",&n);
    map<int,int> lol;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        lol[a]++;
    }
    multiset<int> s;
    for(auto p:lol)
    {
        s.insert(p.second);
    }
    int sol=0;
    for(int i=1;i<=n;i++)
    {
        int uzeto=0;
        vector<int> ret;
        int j=i;
        while(j<=n)
        {
            multiset<int>::iterator it=s.lower_bound(j);
            if(it==s.end())
                break;
            uzeto+=j;
            ret.pb(*it);
            s.erase(it);
            j*=2;
        }
        for(auto p:ret)
            s.insert(p);
        sol=max(sol,uzeto);
    }
    printf("%i\n",sol);
    return 0;
}