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

    ll t;
    cin>>t;
    
    while(t>0)
    {
        ll n;
        cin>>n;
        map<ll,ll> mapper;
        vector<ll> two;
        ll flag = -1;
        for(ll i=0;i<n;i++)
        {
            ll k;
            cin>>k;
            mapper[k]++;
            if(mapper[k]==2)
            {
                two.push_back(k);
            }
            if(mapper[k]==4)
            {
                flag = k;
            }
        }
        if(flag!=-1)
        {
            cout<<flag<<" "<<flag<<" "<<flag<<" "<<flag<<endl;
            t--;
            continue;
        }
        sort(two.begin(),two.end());
        ll min = two[0];
        ll max = two[1];
        double answer = ((min*min)+(max*max)+0.0)/(min*max);
        //cout<<answer<<endl;
        for(int i=1;i<two.size()-1;i++)
        {
            double temp = ((two[i]*two[i])+(two[i+1]*two[i+1] + 0.0))/(two[i]*two[i+1]);
            //cout<<temp<<endl;
            if(temp<answer)
            {
                answer = temp;
                min = two[i];
                max = two[i+1];
            }
        }
        cout<<min<<" "<<min<<" "<<max<<" "<<max<<endl;
        t--;
    }

    return 0;
}