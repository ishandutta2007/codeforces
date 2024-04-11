#include <bits/stdc++.h>
 
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define vll         vector<ll>
#define all(a)      (a).begin(),(a).end()
#define lol         1000000007
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define SIZE        1000005
#define debug(x)    cerr << #x << " = " << x << endl;
#define F first
#define S second
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	std::cerr << name << " = " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " = " << arg1<<" |";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
#define endl        '\n'
#define deci(n) cout<<fixed<<setprecision(n);
const double pi=acos(-1.0);


using namespace std;

void MOD(ll &x)
{
	if (x >= lol) x -= lol;
	if (x < 0) x += lol;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }




void solve()
{
	int n;
	cin>>n;
	map<string, int> m1;
	map<string, string> m2;
	rep(i,0,n)
	{
		string s;
		cin>>s;
		int m = s.size();
		set<string> s1;
		rep(j,0,m)
		{
			string temp = "";
			rep(k,j,m)
			{
				temp += s[k];
				if(s1.find(temp)!=s1.end()) continue;
				m2[temp] = s;
				m1[temp]++;
				s1.insert(temp);
			}
		}
	}
	int q;
	cin>>q;
	while(q--)
	{
		string s;
		cin>>s;
		if(m1.find(s)==m1.end())
		{
			cout<<"0 -"<<endl;
		}
		else
		{
			cout<<m1[s]<<" "<<m2[s]<<endl;
		}
	}
	
	
}



// Remove  debugs!!

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	#ifndef ONLINE_JUDGE
//	    freopen("input.txt", "r", stdin);
//	    freopen("output.txt", "w", stdout);
//	#endif
	int t=1;
//	cin>>t; int i=1;
	while(t--){
		//cout<<"Case #"<<i++<<": ";
		solve();
  	  	//cout<<endl;	
  	}
	return 0;
}