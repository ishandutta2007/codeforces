#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<char> odp;
    int n; cin>>n;
    vector<int> s(101,0);
    vector<int> liczby;
    bool xd=false;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        liczby.push_back(x);
        s[x]++;
    }
    int cnt=0;
    for(int i=0;i<=100;i++)
    {
        if(s[i]==1) cnt++;
    }
    if(cnt%2==0)
    {
        cout<<"YES"<<endl;
        cnt/=2;
        for(int i=0;i<n;i++)
        {
            if(s[liczby[i]]==1 && cnt>0)
            {
                cnt--;
                cout<<"B";
            }
            else cout<<"A";
        }
        return 0;
    }

    else
    {

        cnt/=2;

        for(int i=0;i<n;i++)
        {
            if(s[liczby[i]]==1 && cnt>0)
            {
                cnt--;
                odp.push_back('B');
            }
            else if(s[liczby[i]]>2 && xd==false)
            {
                xd=true;
                odp.push_back('B');
            }
            else
            {
                odp.push_back('A');
            }
        }
    }
    if(xd==false) cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
            cout<<odp[i];
    }
    return 0;
}