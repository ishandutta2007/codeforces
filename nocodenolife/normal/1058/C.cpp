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

    char arr[n];
    int sum = 0;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

        sum+=(int)(arr[i]-'0');
    }
    if(sum==0)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    int i;
    for( i=1;i<sum;i++)
    {
        if(sum%i==0)
        {
            int flag = 1;
            int pos = i;
            int temp = 0;
            for(int j=0;j<n;j++)
            {
                if(temp<pos)
                {
                    temp+=(int)(arr[j]-'0');
                }
                if(temp>pos)
                {
                    flag = 0;
                    break;
                }
                if(temp==pos)
                {
                    temp = 0;
                }
            }
            if(temp!=0)
            {
                flag = 0;
            }
            if(flag==1)
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}