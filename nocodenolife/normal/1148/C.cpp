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
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

int arr[300005];
int pos[300005];
int mini;
vector<pair<int,int>> sol;

bool swap(int i,int j)
{
	if(abs(i-j)<mini)
	{
		//cout<<i<<" "<<j<<endl;
		return false;
	}
 	int num1 = arr[i];
 	int num2 = arr[j];

 	arr[i]=num2;
 	pos[num1] = j;
 	arr[j] = num1;
 	pos[num2] = i;
 	sol.push_back({i,j});
 	return true;
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


    int n;
    cin>>n;
    mini = n/2;

    ForN1(n)
    {
    	cin>>arr[i];
    	pos[arr[i]]=i;
    }

    int val = 0;
    

    for(int i=1;i<=n;i++)
    {
    	if(pos[i]==i)
    		continue;
    	if(abs(pos[i]-i)>=mini)
    	{
    		swap(i,pos[i]);
    		//sol.push_back({0,0});
    		continue;
    	}

    	if(i>n/2)
    	{
    		swap(1,pos[i]);
    		swap(1,i);
    		swap(1,pos[1]);
    		//sol.push_back({1,1});
    		continue;
    	}
    	if(pos[i]<=n/2)
    	{
    		swap(pos[i],n);
    		swap(i,n);
    		//sol.push_back({2,2});
    		continue;
    	}
    	swap(pos[i],1);
    	swap(1,n);
    	swap(i,n);
    	swap(1,pos[1]);
    	//sol.push_back({3,3});
    }

    cout<<sol.size()<<endl;
    ForA1(sol.size())
    {
    	cout<<sol[i].first<<" "<<sol[i].second<<endl;
    }

    return 0;
}