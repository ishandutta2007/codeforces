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

    string s;
    cin>>s;
    ll n = s.length();

    ll begin = 1;
    ll end = 1;
    for(ll i=1;i<n;i++)
    {
        if(s[i]!=s[i-1])
            begin++;
        else
            break;
    }

    for(ll i=n-2;i>=0;i--)
    {
        if(s[i]!=s[i+1])
            end++;
        else
            break;
    }
    ll answer;
    if(s[0]==s[n-1])
    {
        answer = max(begin, end);
    }
    else
    {
        answer = begin+end;
        if(answer>n)
            answer = n;
    }
    ll mn  = 1;
    for(ll i=1;i<n;i++)
    {
        if(s[i]!=s[i-1])
        {
            mn++;
        }
        else
        {
            if(mn>answer)
                answer = mn;
            mn = 1;
        }
    }
    if(mn>answer)
        answer = mn;

    cout<<answer<<endl;
    return 0;
}