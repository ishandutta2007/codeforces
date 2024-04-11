#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=10005;
vector<int> czy(nax,0);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m,n; cin>>m>>n;
    vector<int> a[m];
    for(int i=0;i<m;i++)
    {
        int s; cin>>s;
        for(int j=0;j<s;j++)
        {
            int x; cin>>x;
            a[i].push_back(x);
        }
    }
    int cnt=1;
    for(int i=0;i<m;i++)
    for(int i=0;i<m;i++)
    {
        for(int j=i+1;j<m;j++)
        {
            cnt++;
            bool dobre=false;
            int roz1=a[i].size();
            int roz2=a[j].size();
            for(int k=0;k<roz1;k++)
            {
                czy[a[i][k]]=cnt;
            }
            for(int k=0;k<roz2;k++)
            {
                if(czy[a[j][k]]==cnt)
                {
                    dobre=true;
                    break;
                }
            }
            if(dobre==false)
            {
                cout<<"impossible";
                return 0;
            }
        }
    }
    cout<<"possible";
    return 0;
}