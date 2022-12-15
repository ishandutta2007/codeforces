#include <bits/stdc++.h>
using namespace std;

int n,a,b;
string s;
int lis1[1000001],lis2[1000001],hlis[1000001];

int main()
{
    //freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin>>s>>a>>b;
    n=s.length();
    if (n==1)
    {
        cout<<"NO";
        return 0;
    }
    lis1[0]=(s[0]-'0')%a;
    hlis[0]=1%b;
    lis2[0]=(s[n-1]-'0')%b;
    for (int i=1;i<n-1;i++)
    {
        hlis[i]=(10*hlis[i-1])%b;
        lis1[i]=(10*lis1[i-1]+s[i]-'0')%a;
        lis2[i]=(lis2[i-1]+(s[n-1-i]-'0')*hlis[i])%b;
    }
    for (int i=0;i<n-1;i++)
    {
        if(s[i+1]!='0' && lis1[i]==0 && lis2[n-2-i]==0)
        {
            cout<<"YES"<<endl;
            for (int j=0;j<=i;j++) cout<<s[j];
            cout<<endl;
            for (int j=i+1;j<n;j++) cout<<s[j];
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}