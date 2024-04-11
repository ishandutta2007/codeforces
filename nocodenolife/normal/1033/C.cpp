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

    ll n;
    cin>>n;

    if(n==1)
    {
        cout<<"B"<<endl;
        return 0;
    }

    ll kept[n+1];
    char answer[n+1];
    ll arr[n+1];

    for(ll i=1;i<=n;i++)
    {
        cin>>arr[i];
        kept[arr[i]] = i;
        answer[i] = 'D';
    }

    answer[n] = 'B';
    ll pos, step;
    for(ll i=n-1;i>1;i--)
    {
        step = i;
        pos = kept[i] - step;
        while(pos>0)
        {
            if(arr[pos] > i)
            {
                if(answer[arr[pos]]=='B')
                {
                    answer[i] = 'A';
                    break;
                }
            }
            pos-=step;
        }

        pos = kept[i] + step;
        while(pos<=n)
        {
            if(arr[pos] > i)
            {
                if(answer[arr[pos]]=='B')
                {
                    answer[i] = 'A';
                    break;
                }
            }
            pos+=step;
        }

        if(answer[i]!='A')
        {
            answer[i] = 'B';
        }
    }
    answer[1]= 'A';
    for(ll i=1;i<=n;i++)
    {
        cout<<answer[arr[i]];
    }
    cout<<endl;
    return 0;
}