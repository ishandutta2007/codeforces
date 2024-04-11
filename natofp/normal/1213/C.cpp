#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

map<int,int> xd;

int main()
{
    int q; cin>>q;
    while(q--)
    {
        ll n,m; cin>>n>>m;
        ll ile=n/m;
        ll res=0;
        xd.clear();
        vector<int> jd;
        int j=1;
        while(1)
        {
            ll akt=j*m;
            if(xd[akt%10]==1)
            {
                j--; break;
            }
            else
            {
                jd.push_back(akt%10);
                xd[akt%10]++;
            }
            j++;
        }
        ll dlg=jd.size();
        ll suma=0;
        for(int i=0;i<jd.size();i++) suma+=jd[i];
        ll cykle=ile/dlg;
        //cout<<"XD"<<cykle<<endl;
        res+=cykle*suma;
        ile-=cykle*dlg;
        //cout<<"XD"<<ile<<endl;
        for(int i=0;i<ile;i++) res+=jd[i];
        cout<<res<<endl;
    }
    return 0;
}