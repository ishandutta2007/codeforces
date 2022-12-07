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

    int n, a,b;
    cin>>n>>a>>b;
    int answer = 1;

    while(!((a-b==1&&b%2==1)||(b-a==1&&a%2==1)))
    {
        answer++;
        if(a%2==0)
        {
            a = a/2;
        }
        else
        {
            a = (a+1)/2;
        }
        if(b%2==0)
        {
            b = b/2;
        }
        else
        {
            b = (b+1)/2;
        }

    }
    int final = 1;
    int rounds = 0;
    while(final!=n)
    {
        final*=2;
        rounds++;
    }
    if(answer==rounds)
    {
        cout<<"Final!"<<endl;
    }
    else
    {
        cout<<answer<<endl;
    }

    return 0;
}