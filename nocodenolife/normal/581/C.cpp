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

typedef struct _skill
{
    int modded;
    int points;
}skill;

bool waytosort(skill a, skill b)
{
    return a.modded>b.modded;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    skill arr[n];

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr[i].points = x/10;
        arr[i].modded = x%10;
    }

    sort(arr,arr+n, waytosort);

    for(int i=0;i<n;i++)
    {
        if(arr[i].points ==10)
        {
            continue;
        }
        int req = 10 - arr[i].modded;
        if(k>=req)
        {
            k-= req;
            arr[i].modded = 0;
            arr[i].points +=1;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(arr[i].points ==10)
        {
            continue;
        }
        int can = k/10;
        int req = 10 - arr[i].points;
        if(req<=can)
        {
            k -= req*10;
            arr[i].points = 10;
        }
        else
        {
            k-= can*10;
            arr[i].points += can;
        }

        if(can==0)
            break;
    }

    int answer = 0;
    for(int i=0;i<n;i++)
    {
        answer+= arr[i].points;
    }


    cout<<answer<<endl;
    
    return 0;
}