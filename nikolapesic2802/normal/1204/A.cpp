#include <bits/stdc++.h>

#define ll long long
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()

using namespace std;

int main()
{
	string s;
	cin >> s;
	int ima=0;
	for(int i=1;i<s.size();i++)
		if(s[i]=='1')
			ima=1;
	cout <<(s.size()+ima)/2;
}