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
#define vll vector<ll>
#define F first
#define S second
#define debug(x)    cerr << #x << " = " << x << endl;
#define mem(x) memset(x,false,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,x;
    cin>>n>>x;
    
    int arr[n+1];
    vector<int>pos[x+1];
    int maxi[n+1];
    maxi[0]=0;
    ForN1(n)
    {
        cin>>arr[i];
        pos[arr[i]].push_back(i);
        maxi[i] = max(maxi[i-1],arr[i]);
    }
    int val = x;
    int lst = n+2;
    int s;
    while(val>1)
    {
        s = pos[val].size();
        if(s==0)
        {
            val--;
            continue;
        }
        if(pos[val][s-1]>lst)
            break;
        lst = pos[val][0];
        val--;
    }
    long long int ans = x-val+1;
    //cout<<ans<<endl;
    int prev = val,y,z;
    lst =pos[1].size();
    if(lst!=0)
    {
        lst = pos[1][lst-1];
    }
    for(int i=2;i<=x;i++)
    {
        s = pos[i-1].size();
        if(s==0)
        {
            y = max(prev,i);
            ans+= x-y+1;
        }
        else
        {
            y = max(val,i);
            y = max(y,maxi[pos[i-1][s-1]]);
            prev = y;
            ans+= x-y+1;
        }
        s = pos[i].size();
        if(s!=0)
        {
            if(pos[i][0]<lst)
                break;
            lst = pos[i][s-1];
        }
    }
    
    
    cout<<ans<<endl;
    return 0;
}