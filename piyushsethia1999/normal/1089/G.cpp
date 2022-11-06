#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define VV vector
#define pb push_back
#define bitc  __builtin_popcountl
#define m_p make_pair
#define inf 200000000000000
#define MAXN 1000001
#define eps 0.0000000001
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
string char_to_str(char c){string tem(1,c);return tem;}
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();

//////////////

#define S second
#define F first
#define int long long 

/////////////



signed main()
{
    fastio;
    #ifndef ONLINE_JUDGE
        freopen("inputf.in","r",stdin);
        freopen("outputf.in","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t)
    {
        --t;
        int d;
        cin>>d;
        int a[7];
        int c=0;
        for(int i=0;i<7;++i)
        {
            cin>>a[i];
            if(a[i])
                ++c;
        }
        int ans=inf;
        for(int i=0;i<=c;++i)
        {
            for(int j=0;j<=c;++j)
            {
                if(i+j<=d)
                {
                    if((d-i-j)%c==0)
                    {
                        int x=0,y=0;
                        int vv=0;
                        if(i!=0)
                        for(int k=6;k>=0;--k)
                        {
                            vv+=a[k];
                            ++x;
                            if(vv==i)
                                break;
                        }
                        vv=0;
                        if(j!=0)
                        for(int k=0;k<7;++k)
                        {
                            vv+=a[k];
                            ++y;
                            if(vv==j)
                                break;
                        }
                        ans=min(ans,x+y+((d-i-j)/c)*7);
                    }
                }
            }
        }
        if(d<=c)
        {
            for(int i=0;i<7;++i)
            {
                int vv=0;
                for(int j=i;j<7;++j)
                {
                    vv+=a[j];
                    if(vv>=d)
                    {
                        ans=min(ans,j-i+1);
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
}