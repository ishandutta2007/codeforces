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

string HexToBin(char hexdec) 
{ 
   switch (hexdec) { 
        case '0': 
            return "0000"; 
            break; 
        case '1': 
            return "0001"; 
            break; 
        case '2': 
            return "0010"; 
            break; 
        case '3': 
            return "0011"; 
            break; 
        case '4': 
            return "0100"; 
            break; 
        case '5': 
            return "0101"; 
            break; 
        case '6': 
            return "0110"; 
            break; 
        case '7': 
            return "0111"; 
            break; 
        case '8': 
            return "1000"; 
            break; 
        case '9': 
            return "1001"; 
            break; 
        case 'A': 
        case 'a': 
            return "1010"; 
            break; 
        case 'B': 
        case 'b': 
            return "1011"; 
            break; 
        case 'C': 
        case 'c': 
            return "1100"; 
            break; 
        case 'D': 
        case 'd': 
            return "1101"; 
            break; 
        case 'E': 
        case 'e': 
            return "1110"; 
            break; 
        case 'F': 
        case 'f': 
            return "1111"; 
            break; 
        default: 
            cout << "\nInvalid hexadecimal digit "
                 << hexdec; 
        } 
}


ll n;
char table[5205][1305];
vector<ll> isdistinct;

ll issamerow(ll fir, ll sec)
{
	ForA1(n/4)
	{
		if(table[fir][i]!=table[sec][i])
			return 0;
	}
	return 1;
}

ll checker(ll fir)
{
	char arr[n];
	string k;
	ll index = 0;
	ForA1(n/4)
	{
		k = HexToBin(table[fir][i]);
		for(ll v=0;v<4;v++)
		{
			arr[index] = k[v];
			index++;
		}
	}

	ll div = n;

	ll counter =1;
	ForN1(n-1)
	{
		if(arr[i] == arr[i-1])
		{
			counter++;
		}
		else
		{
			div = __gcd(div,counter);
			counter=1;
		}
	}
	div = __gcd(div,counter);

	return div;
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
	
	cin>>n;

	ForA1(n)
	{
		ForA2(n/4)
		{
			cin>>table[i][j];
		}
	}

	ll div = n;
	ll counter =1;
	isdistinct.push_back(0);
	ForN1(n-1)
	{
		if(issamerow(i,i-1) == 1)
		{
			counter++;
		}
		else
		{
			div = __gcd(div,counter);
			counter=1;
			isdistinct.push_back(i);
		}
	}
	div = __gcd(div,counter);

	if(div==1)
	{
		cout<<div<<endl;
		return 0;
	}

	ll temp;
	for(ll i=0;i<isdistinct.size();i++)
	{
		temp = checker(isdistinct[i]);
		div = __gcd(temp,div);
		if(div==1)
		{
			cout<<div<<endl;
			return 0;
		}
	}

	cout<<div<<endl;
    return 0;
}