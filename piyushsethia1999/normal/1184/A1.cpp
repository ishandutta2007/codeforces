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
	int r;
	cin>>r;
	for(int x=1;x*x<=r;++x)
	{
		int v=r-x*x-x-1;
		if(v>0&&v%(2*x)==0)
		{
			cout<<x<<" "<<v/(2*x);
			return 0;
		}
	}
	cout<<"NO";
}