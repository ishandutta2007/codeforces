#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
int lef[1000001];
int righ[1000001];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int a,b;
    cin>>a>>b;
    int n=s.length();
    lef[0]=((int)s[0]-48)%a;
    for(int i=1;i<n;i++)
    {
        lef[i]=(lef[i-1]*10+((int)s[i]-48))%a;
    }
    righ[n-1]=((int)s[n-1]-48)%b;
    int p=1;
    for(int i=n-2;i>=0;i--)
    {
        p=(p*10)%b;
        righ[i]=(((int)s[i]-48)*p+righ[i+1])%b;
    }
    bool q1=false;
    for(int i=1;i<n;i++)
    {
        if(s[i]!='0')
        {
            if(lef[i-1]==0 && righ[i]==0)
            {
                cout<<"YES"<<endl;
                for(int j=0;j<i;j++) cout<<s[j];
                cout<<endl;
                for(int j=i;j<n;j++) cout<<s[j];
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
}