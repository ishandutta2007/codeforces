#include <bits/stdc++.h>
typedef long long int ll;
#define finc(i,a,b) for(ll i = a; i<b;i++)
#define fdec(i,a,b) for(ll i = a; i>=b;i--)
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pair pair<int,int>
#define F first
#define S second
#define mem(x) memset(x,0,sizeof(x))

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll arr[n];
    finc(i,0,n)
    {
        cin>>arr[i];
    }
    ll left = m;
    finc(i,0,n)
    {
        ll write = arr[i];
        if(write<left)
        {
            left-= write;
            cout<<"0 ";
            continue;
        } 
        write -= left;
        ll turn = (write/m)+1;
        left = m - write%m;
        cout<<turn<<" ";

    }
    cout<<endl;
    return 0;
}