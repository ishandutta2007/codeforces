#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int INF=(long long int)4294967296;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    INF--;
    int l; cin>>l;
    long long int x=0;
    vector<int> xd;
    vector<int> xd2;
    for(int i=1;i<=l;i++)
    {
        string s; cin>>s;
        if(s=="for")
        {
            int n; cin>>n;
            xd.push_back(n);
            if(n!=1) xd2.push_back(n);
        }
        else if(s=="end")
        {
            if(xd.back()!=1) xd2.pop_back();
            xd.pop_back();
        }
        else
        {
            long long int mnoznik=1;
            for(int i=0;i<xd2.size();i++)
            {
                mnoznik*=(long long int)xd2[i];
                if(mnoznik+x>INF)
                {
                    cout<<"OVERFLOW!!!"<<endl;
                    return 0;
                }
            }
            x+=mnoznik;
            if(x>INF)
                {
                    cout<<"OVERFLOW!!!"<<endl;
                    return 0;
                }
        }
    }
    cout<<x<<endl;
    return 0;
}