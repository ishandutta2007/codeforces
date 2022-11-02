#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;




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
        int n,x,l=0;
        char ch='a';
        cin>>n;
        x=n;
        while(x%2==0)
        {
            l++;
            x/=2;
        }
        int val[30][n+7];
        string str;
        cin>>str;
        ch+=l;
        for(int i=0;i<n;i++)
        {
            if(str[i]==ch) val[0][i]=0;
            else val[0][i]=1;
        }
        for(int i=1;i<=l;i++)
        {
            ch--;
            int p=pow(2,i);
            int it=0;
            for(int j=0;j<n/p;j++)
            {
                int res1=val[i-1][2*j],res2=val[i-1][2*j+1];
                for(int l=0;l<p/2;l++)
                {
                    if(str[it]!=ch) res2++;
                    it++;
                }
                for(int l=0;l<p/2;l++)
                {
                    if(str[it]!=ch) res1++;
                    it++;
                }
                val[i][j]=min(res1,res2);
            }
        }
        cout<<val[l][0]<<endl;
    }

    return 0;
}