#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	ll n;
	cin >> n;
	std::vector<string> v(n);
	std::vector<int> ch(n, 0);
	std::map<ll, ll> mapleft;
	std::map<ll, ll> mapright;
	int c;
	ll total = 0;
	stack<char> s;
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		for (int j = 0; j < v[i].size(); ++j)
		{
			if(s.empty()) {
				s.push(v[i][j]);
			}
			else if (v[i][j] == ')') {
				if(s.top() == '('){
					s.pop();
				}
				else{
					s.push(')');
				}
			}
			else
				s.push('(');
		}
		int right = 0;
		int left = 0;
		char ch;
		while(!s.empty()) {
			ch = s.top();
			if(s.top() == '(')
				right++;
			else
				left++;
			s.pop();
		}
		if(right == 0 && left == 0){
			mapleft[0]++;
		}
		else {
			if (right==0)
				mapleft[left]++;
			else if(left == 0)
				mapright[right]++;
		}
	}
	for(auto i = mapleft.begin(); i != mapleft.end(); i++)
	{
		if(i->first != 0)
			total += (mapright[i->first])*(i->second);
	}
	total += (mapleft[0])*(mapleft[0]);
	cout<<total;
}