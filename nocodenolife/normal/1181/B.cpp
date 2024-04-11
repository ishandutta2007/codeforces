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

string findSum(string str1, string str2) 
{ 
    // Before proceeding further, make sure length 
    // of str2 is larger. 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Reverse both of strings 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
  
        // Calculate carry for next step 
        carry = sum/10; 
    } 
  
    // Add remaining digits of larger number 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining carry 
    if (carry) 
        str.push_back(carry+'0'); 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
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

    ll n;
    cin>>n;
    string s;
    cin>>s;

    ll x = n/2;
    string min1 = "",min2="";
    for(ll i=0;i<=n;i++)
    {
    	min1.push_back('9');
    	min2.push_back('9');
    }
    string fir,sec;

    for(ll i=x;i>0;i--)
    {
    	if(s[i]=='0')
    		continue;
    	else
    	{
    		min1 = findSum(s.substr(0,i),s.substr(i));
    		break;
    	}
    }
    //cout<<min1<<endl;

    for(ll i=x+1;i<n;i++)
    {
    	if(s[i]=='0')
    		continue;
    	else
    	{
    		min2 = findSum(s.substr(0,i),s.substr(i));
    		break;
    	}
    }
    //cout<<min2<<endl;

    if(min1.length()>min2.length())
    {
    	cout<<min2<<endl;
    }
    else if(min1.length()<min2.length())
    {
    	cout<<min1<<endl;
    }
    else
    {
    	if(min1<min2)
    		cout<<min1<<endl;
    	else
    		cout<<min2<<endl;
    }

    return 0;
}