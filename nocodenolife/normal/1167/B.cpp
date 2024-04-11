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

pair<int,int> findNum(int z)
{
	int arr[6] = {4,8,15,16,23,42};
    for(ll i=0;i<6;i++)
    {
    	for(ll j=i+1;j<6;j++)
    	{
    		if(arr[i]*arr[j]==z)
    		{
    			return make_pair(arr[i],arr[j]);
    		}
    	}
    }
    return make_pair(0,0);
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[6] = {4,8,15,16,23,42};
    /*std::vector<int> v;
    for(ll i=0;i<6;i++)
    {
    	for(ll j=i+1;j<6;j++)
    	{
    		v.push_back(arr[i]*arr[j]);
    	}
    }*/
    
    ll fir,sec;
    pair<int,int> z1,z2,z3,z4;
    int a[4];

    cout<<"? 1 2"<<endl;
    fflush(stdout);
    cin>>fir;
    z2 = findNum(fir);
    a[0] = z2.first;
    a[1] = z2.second;

    cout<<"? 1 3"<<endl;
    fflush(stdout);
    cin>>sec;
    z1 = findNum(sec);
    a[2] = z1.first;
    a[3] = z1.second;

    sort(a,a+4);
    for(ll i=0;i<3;i++)
    {
    	if(a[i]==a[i+1])
    		arr[0] = a[i];
    }
    arr[1] = fir/arr[0];
    arr[2] = sec/arr[0];


    cout<<"? 4 5"<<endl;
    fflush(stdout);
    cin>>fir;
    z3 = findNum(fir);
    a[0] = z3.first;
    a[1] = z3.second;

    cout<<"? 4 6"<<endl;
    fflush(stdout);
    cin>>sec;
    z4 = findNum(sec);
    a[2] = z4.first;
    a[3] = z4.second;

    sort(a,a+4);
    for(ll i=0;i<3;i++)
    {
    	if(a[i]==a[i+1])
    		arr[3] = a[i];
    }
    arr[4] = fir/arr[3];
    arr[5] = sec/arr[3];

    cout<<"! ";
    ForA1(6)
    {
    	cout<<arr[i]<<" ";
    }
    cout<<endl;
    fflush(stdout);
    return 0;

}