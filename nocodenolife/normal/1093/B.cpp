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

    int arr[26];
    string s;
    int temp;
    char c;
    ForA1(n)
    {
        cin>>s;
        for(int j=0;j<26;j++)
        {
            arr[j]=0;
        }
        for(int j=0;j<s.length();j++)
        {
            arr[(int)(s[j]-'a')]++;
        }
        temp = 0;
        for(int j=0;j<26;j++)
        {
            if(arr[j]>0)
                temp++;
        }
        if(temp==1)
        {
            cout<<"-1"<<endl;
            continue;
        }
        for(int j=0;j<26;j++)
        {
            c = 'a'+j;
            for(int k=0;k<arr[j];k++)
            {
                cout<<c;
            }
        }
        cout<<endl;
    }

    return 0;
}