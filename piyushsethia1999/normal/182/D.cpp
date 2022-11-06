#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;
const int N = 100000;

int findshortest(string s) 
{
	int si = s.size();
	int temp;
	std::vector<int> A(si);
	A[0] = 0;
	for (int i = 1; i < si; ++i)
	{
		temp = A[i-1];
		while(temp > 0 && s[i] != s[temp])
			temp = A[temp-1];
		if(s[i] == s[temp]) temp++;
		A[i] = temp;
	}
	if(si%(si - A[si-1]))
		return si;
	else return (si-A[si-1]);
}

int gcd(int a, int b) {
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); 
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	string s1, s2;
	cin>>s1>>s2;
	int sl1 = findshortest(s1);
	int sl2 = findshortest(s2);
	if(s1.substr(0, sl1) == s2.substr(0, sl2)) {
		int count = 0;
		int l1 = s1.size();
		int l2 = s2.size();
		int l = gcd(l1, l2);
		for (int i = sl1; i <= l; i += sl1)
		{
			if(l % i == 0)
				count++;
		}
		cout<<count;
	}
	else {
		cout<<0;
	}
}