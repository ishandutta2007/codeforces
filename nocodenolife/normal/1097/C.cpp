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

int main()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,len,num,sec,ans=0,flag;
    cin>>n;
    string s;
    map<int,int> mapper;
    char check;

    ForA1(n)
    {
    	cin>>s;
    	num=0;
    	len = s.length();
    	stack<char> sta;

    	for(ll j=0;j<len;j++)
    	{
    		if(sta.empty())
    		{
    			sta.push(s[j]);
    		}
    		else
    		{
    			if(sta.top()==s[j])
    			{
    				sta.push(s[j]);
    			}
    			else
    			{
    				if(s[j]=='(')
    					sta.push(s[j]);
    				else
    					sta.pop();
    			}
    		}
    	}
    	flag = 0;
    	num = sta.size();

    	if(!sta.empty())
    	{
    		check = sta.top();
    		if(check=='(')
    			num*=-1;
    		while(!sta.empty())
    		{
    			if(sta.top()!=check)
    			{
    				flag = 1;
    				break;
    			}
    			sta.pop();
    		}
    	}
    	if(flag==1)
    		continue;


    	sec = -1 * num;

    	if(mapper[sec]==0)
    	{
    		mapper[num]++;
    	}
    	else
    	{
    		ans++;
    		mapper[sec]--;
    	}

    }

    cout<<ans<<endl;

    return 0;
}