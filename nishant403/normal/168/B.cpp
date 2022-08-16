//AUTHOR : TIRTH JARSANIA
//COLLEGE : DAIICT

#include<bits/stdc++.h>
using namespace std;

#define INF LONG_LONG_MAX
#define MINF LONG_LONG_MIN
#define bp __builtin_popcountll
#define ll long long int
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<ll,ll>
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define minQueue priority_queue<pii,vector<pii>,greater<pii> > 
#define maxQueue priority_queue<pii> 
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL))
 
int main()
{
	FAST;
	
	string s;
	bool f = false, ff = true;
	
	while (getline(cin, s)){
		ff = true;
		
		for (int i=0; i<s.size(); i++){
 
			if (s[i] != ' '){
				ff = false;
				if (s[i] != '#'){
					for (int i=0; i<s.size(); i++){
						if (s[i] != ' ') cout << s[i];
					}
					f = true;
 
				} else {
					if (f) cout << endl;
					cout << s << endl; 
					f = false;
				}
				break;
			} 
		}
		if (ff)f = true;
	}
	if (f) cout << endl;
	return 0;
}