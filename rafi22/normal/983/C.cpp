#include <bits/stdc++.h>

//#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;
int id[10][10][10][10];
vector<int>vec[807];
map<vector<int>,int>mapa;
int DP[2007][800][10][4];
int a[2007];
int b[2007];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n;
        cin>>n;
        set<vector<int>>S;
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                for(int k=0;k<10;k++)
                {
                    for(int l=0;l<10;l++)
                    {
                        vector<int>V;
                        V.pb(i);
                        V.pb(j);
                        V.pb(k);
                        V.pb(l);
                        sort(all(V));
                        S.insert(V);
                    }
                }
            }
        }
        int it=1;
        for(auto x:S)
        {
            mapa[x]=it;
            vec[it++]=x;
        }
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                for(int k=0;k<10;k++)
                {
                    for(int l=0;l<10;l++)
                    {
                        vector<int>V;
                        V.pb(i);
                        V.pb(j);
                        V.pb(k);
                        V.pb(l);
                        sort(all(V));
                        id[i][j][k][l]=mapa[V];
                    }
                }
            }
        }
        for(int i=0;i<=n;i++) for(int j=0;j<it;j++) for(int l=0;l<10;l++) for(int q=0;q<4;q++) DP[i][j][l][q]=inf;
        DP[0][1][1][0]=0;
        for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
        for(int i=0;i<=n;i++)
        {
            for(int q=0;q<4;q++)
            {


            for(int j=1;j<it;j++)
            {
                for(int l=1;l<10;l++)
                {


                        if(DP[i][j][l][q]==inf) continue;
                        vector<int>x=vec[j];
                       // cout<<i<<endl;
                       // for(auto y:x) cout<<y<<" ";
                       // cout<<endl;
                        //cout<<l<<endl;
                        if(x[0]==0)
                        {
                            x[0]=b[i+1];
                            DP[i+1][id[x[0]][x[1]][x[2]][x[3]]][a[i+1]][0]=min(DP[i+1][id[x[0]][x[1]][x[2]][x[3]]][a[i+1]][0],DP[i][j][l][q]+1+abs(l-a[i+1]));
                            x[0]=0;
                        }
                        for(int k=0; k<4; k++)
                        {
                            int c=1;
                            while(k<3&&x[k+1]==x[k])
                            {
                                k++;
                                c++;
                            }
                            int xd=x[k];
                            if(xd)
                            {
                                //cout<<"LOL"<<xd<<endl;
                                for(int y=k; y>k-c; y--) x[y]=0;
                               // for(auto y:x) cout<<y<<" ";
                                //cout<<endl;
                                DP[i][id[x[0]][x[1]][x[2]][x[3]]][xd][q+1]=min(DP[i][id[x[0]][x[1]][x[2]][x[3]]][xd][q+1],DP[i][j][l][q]+c+abs(l-xd));
                                for(int y=k; y>k-c; y--) x[y]=xd;
                            }
                        }

                }
            }
            }
        }
        int ans=inf;
        for(int i=1;i<10;i++) for(int q=0;q<4;q++) ans=min(ans,DP[n][1][i][q]);
        cout<<ans;
    }

    return 0;
}