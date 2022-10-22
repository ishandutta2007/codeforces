#include<bits/stdc++.h>
using namespace std;

int T;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--)
    {
        int n;
        map<pair<int,int>,int>cnt,c;
        cin>>n;
        for(int i=0;i<3;i++)
        {
            int a,b;
            cin>>a>>b;
            cnt[{a,b}]++;
            c[{a&1,b&1}]++;
        }
        int x,y;
        cin>>x>>y;
        if(!c[{x&1,y&1}])
        {
            cout<<"No\n";
        }
        else
        {
            bool ok=1;
            if(cnt[{1,1}]&&!cnt[{2,2}])
            {
                ok=(x==1||y==1);
            }
            else if(cnt[{n,n}]&&!cnt[{n-1,n-1}])
            {
                ok=(x==n||y==n);
            }
            else if(cnt[{1,n}]&&!cnt[{2,n-1}])
            {
                ok=(x==1||y==n);
            }
            else if(cnt[{n,1}]&&!cnt[{n-1,2}])
            {
                ok=(y==1||x==n);
            }
            else
                ok=1;
            cout<<(ok?"Yes\n":"No\n");
        }
    }
}