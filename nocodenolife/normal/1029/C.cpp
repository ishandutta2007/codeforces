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

typedef struct __range{
    ll begin;
    ll end;
}range;

bool waytosort(range a, range b)
{
    if(a.begin==b.begin)
    {
        return a.end>b.end;
    }
    return a.begin<b.begin;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    range arr[n];

    int min_end = 1000000000;
    int min_end_2 = 1000000000;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i].begin>>arr[i].end;
        if(arr[i].end < min_end)
        {
            min_end_2 = min_end;
            min_end = arr[i].end;
            continue;
        }
        if(arr[i].end<min_end_2)
        {
            min_end_2 = arr[i].end;
        }

    }


    sort(arr,arr+n, waytosort);
    //int max_begin = arr[n-1].begin;

    int answer = min_end_2 - arr[n-1].begin ;
    int answer2 =  min_end - arr[n-2].begin ;
    //cout<<answer<<" "<<answer2<<endl;
    if(arr[n-1].end == min_end)
    {
        answer = min_end_2 - arr[n-2].begin ;
    }
    else
    {
        answer = max(answer, answer2);
    }

    if(answer<=0)
    {
        cout<<"0"<<endl;
        return 0;
    }
    cout<<answer<<endl;

    

    return 0;
}