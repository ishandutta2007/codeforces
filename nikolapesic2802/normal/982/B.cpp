#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    set<pair<int,int> > in;
    set<pair<int,int> > out;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        in.insert(make_pair(a,i+1));
    }
    char s[2*n+1];
    scanf("%s",s);
    for(int i=0;i<2*n;i++)
    {
        if(s[i]=='0')
        {
            pair<int,int> mesto=*in.begin();
            in.erase(in.begin());
            out.insert(mesto);
            printf("%i ",mesto.second);
        }
        else
        {
            set<pair<int,int> >::iterator it;
            it=out.end();
            it--;
            pair<int,int> mesto=*it;
            out.erase(it);
            printf("%i ",mesto.second);
        }
    }
    return 0;
}