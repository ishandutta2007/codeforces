#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n, m;
	string s, S;
	cin >> n >> m >> S >> s;
	int siz = s.size();
	int Siz = S.size();
	std::vector<int> ccnt(siz, 0);
	for (int i = 0; i < siz; ++i)
	{
		int curr = i;
		for (int j = 0; j < Siz; ++j)
			if(s[curr] == S[j])
			{
				curr++;
				ccnt[i]++;
				if(curr == siz)
					curr = 0;
			}
	}
	int totalcnt = 0;
	int curr = 0;
	while(n--)
	{
		totalcnt += ccnt[curr];
		curr = (curr + ccnt[curr])%siz;
	}
	cout << ((totalcnt/siz)/m);
}