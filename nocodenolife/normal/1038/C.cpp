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

    ll a[n];
    ll b[n];

    ll score_a = 0;
    ll score_b= 0;

    ForA1(n)
    {
        cin>>a[i];
    }
    ForA1(n)
    {
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);

    ll a_counter = n-1;
    ll b_counter = n-1;

    while(a_counter!=-1 || b_counter!=-1)
    {
        if(b_counter==-1)
        {
            score_a+= a[a_counter];
            a_counter--;
        }
        else if(a_counter==-1)
        {
            b_counter--;
        }
        else if(a[a_counter]>b[b_counter])
        {
            score_a+= a[a_counter];
            a_counter--;
        }
        else{
            b_counter--;
        }



        if(a_counter==-1)
        {
            score_b+= b[b_counter];
            b_counter--;
        }
        else if(b_counter==-1)
        {
            a_counter--;
        }
        else if(b[b_counter]>a[a_counter])
        {
            score_b+= b[b_counter];
            b_counter--;
        }
        else{
            a_counter--;
        }
    }

    cout<<score_a-score_b<<endl;
    return 0;
}