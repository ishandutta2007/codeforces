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
	int n;
	cin>>n;
	int s[3001];
	int c[3001];
	for (int i = 0; i < n; ++i)
	{
		cin>>s[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>c[i];
	}
	int first[3001];
	std::vector<int> second(n, 0);
	std::vector<int> third(n, 0);
	second[0] = 1000000000;
	for (int i = 0; i < n; ++i)
	{
		int min = 100000001;
		for (int j = i-1; j >= 0; --j)
		{
			if(s[i] > s[j] && min > c[j]) {
				min = c[j];
			}
		}
		second[i] = min + c[i];
	}
	for (int i = 0; i < n; ++i)
	{
		int min = 400000001;
		for (int j = i-1; j >= 0; --j)
		{
			if(s[i] > s[j] && min > second[j]) {
				min = second[j];
			}
		}
		third[i] = min + c[i];
	}
	print(second, third);
	int mi = 300000001;
	for (int i = 2; i < n; ++i)
	{
		if(mi > third[i]) {
			mi = third[i];
		}
	}
	if(mi != 300000001)
		cout<<mi;
	else
		cout<<"-1";
}