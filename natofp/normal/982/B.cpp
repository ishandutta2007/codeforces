#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    multiset <pair<int,int> > a;
    multiset <pair<int,int> > b;
    int n,m,x;
    char d;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a.insert(make_pair(x,i));
    }
    for(int i=1;i<=2*n;i++)
    {
        cin>>d;
        if(d=='0')
        {
            if(a.size()==0) return 0;
            pair<int,int> p = *a.begin();
            a.erase(a.begin());
            b.insert(make_pair(-p.first,p.second));
            cout<<p.second<<" ";
        }
        else
        {
            if(b.size()==0) return 0;
            pair<int,int> p = *b.begin();
            b.erase(b.begin());
            cout<<p.second<<" ";

        }

    }

    return 0;
}