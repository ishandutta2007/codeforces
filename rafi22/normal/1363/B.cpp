#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int l=0;l<t;l++)
    {
       /* long long n,x,a,p=0,np=0;
        cin>>n>>x;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            if(a%2==0) p++;
            else np++;
        }
        if(np%2==0) np--;
        if(np>0&&p+np>=x) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;*/
        string str;
        cin>>str;
        int c1=0,c0=0,maxi1=0,maxi=10000007;
        int p1[str.size()+7];
        p1[0]=0;
        int p0[str.size()+7];
        p0[0]=0;
        int n=str.size();
        for(int i=1;i<=str.size();i++)
        {
            p1[i]=p1[i-1];
            p0[i]=p0[i-1];
            if(str[i-1]=='1') p1[i]++;
            else p0[i]++;
        }
        for(int i=1;i<=str.size();i++)
        {
            if(str[i-1]=='1')
            {
                maxi=min(maxi,p0[i]+p1[n]-p1[i]);
                maxi=min(maxi,p1[i-1]+p0[n]-p0[i-1]);
            }
            else
            {
                maxi=min(maxi,p0[i-1]+p1[n]-p1[i-1]);
                maxi=min(maxi,p1[i]+p0[n]-p0[i]);
            }
        }
        cout<<maxi<<endl;
    }
    return 0;
}