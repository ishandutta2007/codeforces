#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    int t;
    scanf("%i",&t);
    while(t--)
    {
        string s;
        cin >>s;
        int niz[3]={};
        vector<int> poz;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                if(niz[0]>0)
                {
                    poz.pb(i);
                }
                else
                {
                    niz[0]++;
                }
            }
            if(s[i]>='a'&&s[i]<='z')
            {
                if(niz[1]>0)
                {
                    poz.pb(i);
                }
                else
                {
                    niz[1]++;
                }
            }
            if(s[i]>='0'&&s[i]<='9')
            {
                if(niz[2]>0)
                {
                    poz.pb(i);
                }
                else
                {
                    niz[2]++;
                }
            }
        }
        if(niz[0]+niz[1]+niz[2]==1)
        {
            int tr=poz[0];
            if(!niz[0])
            {
                s[tr]='A';
                tr++;
            }
            if(!niz[1])
            {
                s[tr]='a';
                tr++;
            }
            if(!niz[2])
            {
                s[tr]='0';
                tr++;
            }
        }
        if(niz[0]+niz[1]+niz[2]==2)
        {
            int tr=poz[0];
            if(!niz[0])
            {
                s[tr]='A';
            }
            if(!niz[1])
            {
                s[tr]='a';
            }
            if(!niz[2])
            {
                s[tr]='0';
            }
        }
        cout << s << endl;
    }
    return 0;
}