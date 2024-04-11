#include <bits/stdc++.h>

typedef unsigned long long int ull;
typedef long double ldb;
typedef long long int ll;

#define ForA1(n)  for (ll i=0; i<n; i++)
#define ForA2(n)  for (ll j=0; j<n; j++)
#define ForA3(n)  for (ll k=0; k<n; k++)
#define ForN1(n)  for (ll i=1; i<=n; i++)
#define ForN2(n)  for (ll j=1; j<=n; j++)
#define ForN3(n)  for (ll k=1; k<=n; k++)

#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pair pair<int,int>
#define F first
#define S second
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int a[n-1][2];
    int b[n-1][2];
    int ans[n][2];
    int temp;
    for(int i=0;i<n-1;i++)
    {
        cin>>temp;
        a[i][0] = temp %2;
        temp/=2;
        a[i][1] = temp%2;
    }
    for(int i=0;i<n-1;i++)
    {
        cin>>temp;
        b[i][0] = temp %2;
        temp/=2;
        b[i][1] = temp%2;

        if(b[i][0]>a[i][0] || b[i][1] > a[i][1])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        ans[i][0] = -1;
        ans[i][1] = -1;
    }

    for(int i=0;i<n-1;i++)
    {
        if(a[i][0]==b[i][0])
        {
            if(ans[i][0]!=-1 && ans[i][0]!=a[i][0])
            {
                cout<<"NO"<<endl;
                return 0;
            }
            if(ans[i+1][0]!=-1 && ans[i+1][0]!=a[i][0])
            {
                cout<<"NO"<<endl;
                return 0;
            }
            ans[i][0] = ans[i+1][0] = a[i][0];
        }
        if(a[i][1]==b[i][1])
        {
            if(ans[i][1]!=-1 && ans[i][1]!=a[i][1])
            {
                cout<<"NO"<<endl;
                return 0;
            }
            if(ans[i+1][1]!=-1 && ans[i+1][1]!=a[i][1])
            {
                cout<<"NO"<<endl;
                return 0;
            }
            ans[i][1] = ans[i+1][1] = a[i][1];
        }
    }

    int start = -1;
    for(int i=0;i<n;i++)
    {
        if(ans[i][0]!=-1)
        {
            start = i;
            break;
        }
    }
    if(start==-1)
    {
        ans[0][0] = 0;
        start = 0;
    }
    for(int i=start-1;i>=0;i--)
    {
        if(ans[i][0]==-1)
            ans[i][0] = (ans[i+1][0]+1)%2;
    }
    for(int i=start+1;i<n;i++)
    {
        if(ans[i][0]==-1)
            ans[i][0] = (ans[i-1][0]+1)%2;
    }


    start = -1;
    for(int i=0;i<n;i++)
    {
        if(ans[i][1]!=-1)
        {
            start = i;
            break;
        }
    }
    if(start==-1)
    {
        ans[0][1] = 0;
        start = 0;
    }
    for(int i=start-1;i>=0;i--)
    {
        if(ans[i][1]==-1)
            ans[i][1] = (ans[i+1][1]+1)%2;
    }
    for(int i=start+1;i<n;i++)
    {
        if(ans[i][1]==-1)
            ans[i][1] = (ans[i-1][1]+1)%2;
    }
    
    for(int i=0;i<n-1;i++)
    {
        if(a[i][0]==1  && b[i][0]==0)
        {
            if(ans[i][0]+ans[i+1][0]!=1)
            {
                cout<<"NO";
                cout<<endl;
                return 0;
            }
        }
        if(a[i][1]==1  && b[i][1]==0)
        {
            if(ans[i][1]+ans[i+1][1]!=1)
            {
                cout<<"NO";
                cout<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++)
    {
        temp = ans[i][1]*2 + ans[i][0];
        cout<<temp<<" ";
    }
    cout<<endl;
    return 0;
}