#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf 
using namespace std;
typedef long long ll;
typedef long double ld;


int main ()
{
	ios_base::sync_with_stdio(false);
	string s;
	int n, k;
	cin>>n >>k >>s;
	
	//sa dwie opcje
	
	int check = 0;
	for (int i=k; i<n; i++)
	{
		if (s[i] > s[i%k]) 
		{
			check = -1;
			break;
		}
		if (s[i] < s[i%k])
		{
			check = 1;
			break;
		}
	}
	if (check==-1)
	{
		//trzeba dodac jeden
		int x = k-1;
		bool add = true;
		while (add)
		{
			if (x==-1)
			{
				assert(0);
				reverse(s.begin(), s.end());
				s.pb('1');
				reverse(s.begin(), s.end());
				break;
			}
			add = false;
			if (s[x]=='9')
			{
				add = true;
				s[x] = '0';
			}
			else s[x]++;
			x--;
		}
	}
	
	rep(i,0,n) s[i] = s[i%k];
	
	cout<<n <<"\n" <<s <<"\n";
}