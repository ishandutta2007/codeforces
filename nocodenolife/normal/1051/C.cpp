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
    map<int,int> mapper;
    map<int, char> answer;
    int arr[n];

    int ones = 0;
    int twos = 0;
    int greater = 0;
    ForA1(n)
    {
        cin>>arr[i];
        mapper[arr[i]]++;

        if(mapper[arr[i]]==1)
        {
            ones++;
        }
        if(mapper[arr[i]]==2)
        {
            twos++;
            ones--;
        }
        if(mapper[arr[i]]==3)
        {
            twos--;
            greater++;
        }

    }

    if(greater==0 && ones%2==1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    
    cout<<"YES"<<endl;

    if(ones%2==0)
    {
        char selector = 'A';
        for(int i=0;i<n;i++)
        {
            answer[arr[i]] = selector;
            if(mapper[arr[i]]==1)
            {
                if(selector=='A')
                    selector = 'B';
                else
                    selector = 'A';
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<answer[arr[i]];
        }
        cout<<endl;
        return 0;
    }

    else{
        char selector = 'A';
        for(int i=0;i<n;i++)
        {
            answer[arr[i]] = selector;
            if(mapper[arr[i]]==1)
            {
                if(selector=='A')
                    selector = 'B';
                else
                    selector = 'A';
            }
        }
        int As=0, Bs=0, maxim;
        for(int i=0;i<n;i++)
        {
            if(mapper[arr[i]]==1)
            {
                if(answer[arr[i]]=='A')
                    As++;
                else
                    Bs++;
            }
            if(mapper[arr[i]]>2)
            {
                maxim = i;
            }
        }

        if(As>Bs)
        {
            answer[arr[maxim]] = 'A';
        }
        else
        {
            answer[arr[maxim]] = 'B';
        }

        for(int i=0;i<n;i++)
        {
            if(i==maxim)
            {
                if(answer[arr[i]]=='A')
                    cout<<"B";
                else
                    cout<<"A";
            }
            else
            {
                cout<<answer[arr[i]];
            }
        }
        cout<<endl;
        return 0;
    }

    return 0;
}