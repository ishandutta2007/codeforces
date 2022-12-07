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

    int candies = n;

    int left[n], right[n], can[n];

    for(int i=0;i<n;i++)
    {
        cin>>left[i];
        can[i] = -1;
    }
    for(int i=0;i<n;i++)
    {
        cin>>right[i];
    }

    int flag , counter, lef,rig;
    while(true)
    {   
        flag =0;
        for(int i=0;i<n;i++)
        {
            if(can[i]==-1)
            {
                flag = 1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++)
            {
                cout<<can[i]<<" ";
            }
            cout<<endl;
            return 0;
        }

        counter = 0;
        for(int i=0;i<n;i++)
        {
            if(left[i]==0 && right[i]==0 && can[i]==-1)
            {
                can[i] = candies;
                counter++;
            }
        }
        if(counter==0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        lef = 0;
        rig = counter;
        for(int i=0;i<n;i++)
        {
            if(can[i] ==candies)
            {
                lef++;
                rig--;
            }
            else{
                left[i]-=lef;
                right[i]-=rig;
            }
        }

        candies-=1;
    }
    return 0;
}