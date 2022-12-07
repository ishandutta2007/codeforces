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
ll dp[1000][1000];
string s;

string removeDuplicates(string S){ 
      
   int n = S.length(); 
  	string c = "";
   // We don't need to do anything for 
   // empty or single character string. 
   if (n < 2) 
     return S; 
     
   // j is used to store index is result 
   // string (or index of current distinct 
   // character)   
   int j = 0; 
  	c=c + S[0];
   // Traversing string  
   for (int i=1; i<n; i++) 
   { 
       // If current character S[i] 
       // is different from S[j] 
       if (S[i] != S[i-1]) 
       { 
           c = c + S[i]; 
       }      
   }    
  
   // Putting string termination 
   // character. 
      
   return c;  
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

    ll len;
    cin>>len;
    string t;
    cin>>t;
    s = removeDuplicates(t);
    //cout<<s<<endl;
    
    ll n = s.length();

    ForA1(n+10)
    {
    	ForA2(n+10)
    		dp[i][j]=0;
    }

    ForA1(n+10)
    	dp[i][i]=1;


    char temp;
    ll k;
    for(ll l = 2;l<=n;l++)
    {
    	for(ll i=0;i<n-l+1;i++)
    	{
    		ll j = i + l -1;
    		temp = s[j];
    		dp[i][j] = dp[i][j-1]+1;
    		for(k = j-1;k>=i;k--)
    		{
    			if(s[k]==temp)
    			{
    				dp[i][j] = min(dp[i][k]+dp[k+1][j-1], dp[i][j] );
    			}
    		}
    	}
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}