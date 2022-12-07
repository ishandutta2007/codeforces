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
#define mem(x) memset(x,-1,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

int arr[17][10005];
int followon[17][17];
int begend[17][17];
int n,m;
int dp[1 << 17][17][17];

int fill_followon(int one, int two)
{
	int mini =  mod;
	// cout<<m;
	for(int i=0;i<m;i++)
	{
		mini = min(mini,abs(arr[one][i]-arr[two][i]));
		// cout<<arr[one][i]-arr[two][i]<<endl;
	}

	followon[one][two] = mini;
	followon[two][one] = mini;
	dp[((1<<one)+(1<<two))][one][two] = mini;
	dp[((1<<one)+(1<<two))][two][one] = mini;
	// cout<<one<<" "<<two<<" "<<((1<<one)+(1<<two))<<endl;
	return mini;
}

int fill_begend(int begin, int end)
{
	int mini =  mod;
	for(ll i=1;i<m;i++)
	{
		mini = min(mini,abs(arr[begin][i]-arr[end][i-1]));
	}

	begend[begin][end] = mini;
	// followon[two][one] = mini;

	return mini;
}

int getdp(int num, int beg, int en)
{
	if(dp[num][beg][en]!=-1)
		return dp[num][beg][en];
	
	int ispow2[17] = {0};
	int temp = num;
	int i=0;
	while(temp>0)
	{
		ispow2[i] = temp%2;
		temp/=2;
		i++;
	}

	temp = 1<<beg;
	int ans = 0;
	for(i=0;i<n;i++)
	{
		if(i==beg || i==en || ispow2[i]==0)
			continue;
		ans = max(ans, min( getdp(num-temp,i,en),followon[beg][i] ) );
	}
	dp[num][beg][en] = ans;

	return ans;
}


int main()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    if(n==1)
    {
    	ForA1(m)
    		cin>>arr[1][i];
    	int ans = mod;
    	ForN1(m-1)
    	{
    		ans = min(ans, abs(arr[1][i]-arr[1][i-1]));
    	}
    	cout<<ans<<endl;
    	return 0;
    }
    mem(dp);

    ForA1(n)
    {
    	ForA2(m)
    	{
    		cin>>arr[i][j];
    		// cout<<arr[i][j];
    	}
    }

    ForA1(n)
    {
    	for(int j=i;j<n;j++)
    	{
    		fill_followon(i,j);
    		// cout<<i<<" "<<j<<" "<<fill_followon(i,j)<<endl;
    	}
    }

    ForA1(n)
    {
    	ForA2(n)
    	{
    		fill_begend(i,j);
    		// cout<<i<<" "<<j<<" "<<fill_begend(i,j)<<endl;
    	}
    }

    int num = 1;
    int temp=1;
    for(int i=1;i<n;i++)
    {    	
    	temp*=2;
    	num+=temp;
    	// cout<<temp<<endl;
    }
    // cout<<num<<endl;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		if(i==j)
    			continue;
    		ans = max(ans,min(getdp(num,i,j),begend[i][j]));
    		// cout<<i<<" "<<j<<" "<<min(getdp(num,i,j),begend[i][j])<<endl;
    	}
    }

    // for(ll i=0;i<num;i++)
    // {
    // 	ForA2(n)
    // 	{
    // 		ForA3(n)
    // 		{
    // 			cout<<i<<" "<<j<<" "<<k<<" "<<getdp(i,j,k)<<endl;
    // 		}
    // 	}
    // }

    cout<<ans<<endl;


    return 0;
}