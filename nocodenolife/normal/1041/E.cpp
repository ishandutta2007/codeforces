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
    ll arr[n] = {0};
    ll checker[n] = {0};

    ll a,b;
    ll mini,maxi;
    ll flag = 1;
    for(ll i=1;i<n;i++)
    {
        cin>>a>>b;
        mini = a>b?b:a;
        maxi = b>a?b:a;

        if(maxi!=n)
        {
            flag =0;
        }
        if(mini>=n)
        {
            flag =0;
        }
        else{
            arr[mini]++;
            checker[mini]++;
        }
    }

    if(flag==0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    
    
    ll counter = n-1;

    for(ll i=n-1;i>=1;i--)
    {
        ll num = checker[i];
        if(num<=0)
            continue;
        if(num==1)
        {
            checker[i] = -1;
        }
        else{
            ll req = num-1;
            ll prev = n;
            while(req>0)
            {
                while(checker[counter]!=0)
                {
                    counter--;
                }
                checker[counter] = -1;
                if(counter>i)
                {
                    cout<<"NO"<<endl;
                    return 0;
                }
                //cout<<prev<<" "<<counter<<endl;
                prev = counter;
                counter--;
                req--;
            }
            //cout<<prev<<" "<<i<<endl;
            checker[i] = -1;
        }
    }
    
    
    
    cout<<"YES"<<endl;
    counter = n-1;

    for(ll i=n-1;i>=1;i--)
    {
        ll num = arr[i];
        if(num<=0)
            continue;
        if(num==1)
        {
            arr[i] = -1;
            cout<<n<<" "<<i<<endl;
        }
        else{
            ll req = num-1;
            ll prev = n;
            while(req>0)
            {
                while(arr[counter]!=0)
                {
                    counter--;
                }
                arr[counter] = -1;
                cout<<prev<<" "<<counter<<endl;
                prev = counter;
                counter--;
                req--;
            }
            cout<<prev<<" "<<i<<endl;
            arr[i] = -1;
        }
    }

    return 0;
}