#include <bits/stdc++.h>

using namespace std;
bool substring(string s1,string s2)
{
    if(s1.size()<=s2.size())
    {
        for(int k=0; k<=s2.size()-s1.size(); k++)
        {
            bool test=true;
            for(int l=0; l<s1.size(); l++)
            {
                if(s1[l]!=s2[l+k])
                {
                    test=false;
                }
            }
            if(test)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int n;
    scanf("%i",&n);
    vector<pair<int,string> > d;
    for(int i=0;i<n;i++)
    {
        char niz[101];
        scanf("%s",niz);
        string s=niz;
        d.push_back(make_pair(s.size(),s));
    }
    sort(d.begin(),d.end());
    bool test=true;
    for(int i=1;i<n;i++)
    {
        if(!substring(d[i-1].second,d[i].second))
        {
            test=false;
        }
    }
    if(test)
    {
        printf("YES\n");
        for(int i=0;i<n;i++)
        {
            cout << d[i].second << endl;
        }
        return 0;
    }
    printf("NO\n");
    return 0;
}