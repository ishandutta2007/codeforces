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

#define modder 998244353
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
    
    ll k;
    cin>>k;
    
    string s;
    cin>>s;
    
    if(k==0)
    {
        ll answer =0;
        ll counter=0;
        ForA1(s.length())
        {
            if(s[i]=='0')
                counter++;
            else
            {
                answer+= (counter*(counter+1))/2;
                counter=0;
            }
        }
        answer+= (counter*(counter+1))/2;
        cout<<answer<<endl;
        return 0;
    }
    
    ll answer = 0;
    ll n = s.length();
    ll arr[n];
    ll count[n+1] = {1};
    arr[0]=(int) (s[0] - '0');
    count[arr[0]]++;
    ForN1(n-1)
    {
        arr[i] = arr[i-1] + (int) (s[i] - '0');
        count[arr[i]]++;
    }
    
    ForA1(n)
    {
        if(arr[i]<k)
            continue;
        answer+= count[(arr[i]-k)];
    }
    cout<<answer<<endl;
    
    return 0;
}