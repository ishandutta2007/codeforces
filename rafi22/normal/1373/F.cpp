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


int n,asum,bsum,l,p,sr,res,lost1,lost2;

int licz(int sr,int arr[],int brr[])
{
    int a[n];
    int b[n];
    for(int i=0;i<n;i++)
    {
        a[i]=arr[i];
        b[i]=brr[i];
    }
    int a1,a2,b1;
    a1=a[0];
    a2=a[1];
    b1=b[0];
    a[0]-=min(a1,b1-sr);
    a[1]-=min(a2,sr);
    b[0]-=min(a1,b1-sr)+min(a2,sr);
    for(int i=1; i<n; i++)
    {
        a1=a[i];
        a2=a[(i+1)%n];
        b1=b[i];
        a[i]-=min(a1,b1);
        b[i]-=min(a1,b1);
        b1=b[i];
        a[(i+1)%n]-=min(a2,b1);
        b[i]-=min(a2,b1);
    }

    int lost=0;
    for(int i=0;i<n;i++) lost+=b[i];
    return lost;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        asum=0;
        bsum=0;
        cin>>n;
        int a[n];
        int b[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            asum+=a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
            bsum+=b[i];
        }
        l=0,p=b[0];
        while(l<=p)
        {
            sr=(l+p)/2;
            lost1=inf,lost2=inf;
            lost1=licz(sr,a,b);
            if(sr+1<=b[0]) lost2=licz(sr+1,a,b);
            if(lost1<=lost2)
            {
                res=lost1;
                p=sr-1;
            }
            else
            {
                res=lost2;
                l=sr+1;
            }
        }
        if(bsum-res>=asum) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}