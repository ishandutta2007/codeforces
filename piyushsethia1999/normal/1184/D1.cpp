#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define VV vector
#define pb push_back
#define bitc  __builtin_popcountl
#define inf 1500000000
#define MAXN 1000001
#define eps 0.0000000001
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
string char_to_str(char c){string tem(1,c);return tem;}
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();

//////////////

#define S second
#define F first
#define int long long

/////////////

signed main()
{
	fastio;
	#ifdef ANIKET_GOYAL
		freopen("inputf.in","r",stdin);
		freopen("outputf.in","w",stdout);
	#endif
	int n,k,m,t;
	cin>>n>>k>>m>>t;
	int a=k-1;
	int b=n-k;
	while(t)
	{
		--t;
		int ty;
		cin>>ty;
		int i;
		cin>>i;
		if(ty==0)
		{
			if(i<=a)
			{
				a=a-i;
			}
			else
			{
				b=i-a-1;
			}
		}
		else
		{
			if(i<=a+1)
				++a;
			else
				++b;
		}
		cout<<a+b+1<<" "<<a+1<<"\n";
	}
}