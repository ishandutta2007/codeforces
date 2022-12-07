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
    ll n,m,q;
    cin>>n>>m>>q;
    string s,t;
    cin>>s>>t;
    ll arr[n];
    finc(i,0,n)
    {
        arr[i]=0;   
    }
    finc(i,0,n)
    {
        int issub = 1;
        for(ll j=0;j<t.size();j++)
        {
            if((i+j>=n) || s[i+j]!=t[j])
            {
                issub = 0;
                break;
            }
        }  
        if(issub)
        {
            arr[i]++;
        }
    }
    finc(i,1,n)
    {
        arr[i]+=arr[i-1];   
    }

    finc(i,0,q)
    {
        ll l,r;
        cin>>l>>r;
        ll dist = r-l+1;
        if(dist<m)
        {
            cout<<"0"<<endl;
            continue;
        }
        l--;
        r--;
        r  = r-m +1;
        if(l==0){
            cout<<arr[r]<<endl;
        }
        else
        {
            cout<<arr[r]-arr[l-1]<<endl;
        }
    }
    return 0;
}