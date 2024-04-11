#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

string DP[100007];
bool is[100007];
int len[100007];

string compress(string s)
{
    if(sz(s)<=10+2*(s.back()=='#')) return s;
    string w="";
    for(int i=0;i<5;i++) w+=s[i];
    w+="...";
    if(s.back()=='#')
    {
        w+=s[sz(s)-4];
        w+=s[sz(s)-3];
    }
    else
    {
        w+=s[sz(s)-2];
        w+=s[sz(s)-1];
    }
    return w;
}

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
        string s;
        cin>>s;
        int n=sz(s);
        s="#"+s+"###";
        DP[n+1]="##";
        DP[n+2]="##";
        for(int i=n;i>0;i--)
        {
            string res="";
            if(s[i]==s[i+1])
            {
                if(s[i]<DP[i+2][0])
                {
                    DP[i]=s[i]+DP[i+2];
                    DP[i]=compress(s[i]+DP[i]);
                    is[i]=1;
                    len[i]=len[i+2]+2;
                }
                else if(s[i]==DP[i+2][0])
                {
                    if(s[i]<DP[i+2][1])
                    {
                        DP[i]=s[i]+DP[i+2];
                        DP[i]=compress(s[i]+DP[i]);
                        is[i]=1;
                        len[i]=len[i+2]+2;
                    }
                    else if(s[i]==DP[i+2][1])
                    {
                        if(is[i+2])
                        {
                            DP[i]=s[i]+DP[i+2];
                            DP[i]=compress(s[i]+DP[i]);
                            is[i]=1;
                            len[i]=len[i+2]+2;
                        }
                        else
                        {
                            DP[i]=DP[i+2];
                            is[i]=is[i+2];
                            len[i]=len[i+2];
                        }
                    }
                    else
                    {
                        DP[i]=DP[i+2];
                        is[i]=is[i+2];
                        len[i]=len[i+2];
                    }
                }
                else
                {
                    DP[i]=DP[i+2];
                    is[i]=is[i+2];
                    len[i]=len[i+2];
                }
            }
            else
            {
                DP[i]=compress(s[i]+DP[i+1]);
                if(DP[i][0]<DP[i][2]) is[i]=1;
                else if(DP[i][0]==DP[i][2]) is[i]=is[i+1];
                len[i]=len[i+1]+1;
            }
        }
        for(int i=1;i<=n;i++)
        {
            while(sz(DP[i])>0&&DP[i].back()=='#') DP[i].pop_back();
            cout<<len[i]<<" "<<DP[i]<<endl;
        }
    }

    return 0;
}