#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(30);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n;
	cin >> n;
	std::vector<int> gseq(n);
	for (int i = 0; i < n; ++i)
		cin >> gseq[i];
	int winner = gseq[n-1];
	std::vector<int> w(n);
	std::vector<int> l(n);
	if(gseq[0] == winner) {
		w[0] = 1;
		l[0] = 0;
	}
	else {
		w[0] = 0;
		l[0] = 1;
	}
	for (int i = 1; i < n; ++i)
	{
		if(gseq[i] == winner) {
			w[i] = w[i-1] + 1;
			l[i] = l[i-1];
		}
		else
		{
			w[i] = w[i-1];
			l[i] = l[i-1] + 1;
		}
	}
	std::vector<std::pair<int, int> > ps;
	print(w, l);
	print("pre ok");
	for (int s = 1; s <= w[n-1]; ++s)
	{
		int curr = 0;
		int ws = 0;
		int ls = 0;
		int wt = 0;
		int lt = 0;
		int lastwin = 0;
		int wi, li;
		bool gameisright = true;
		while(curr < n)
		{
			print(s, curr);
			wi = lower_bound(w.begin(), w.end(), ws + s) - w.begin();
			li = lower_bound(l.begin(), l.end(), ls + s) - l.begin();
			if(wi < li) {
				wt++;
				lastwin = winner;
				curr = wi + 1;
				ls = l[curr - 1];
				ws = w[curr - 1];
			}
			else if(li < wi)
			{
				lt++;
				lastwin = 3 - winner;
				curr = li + 1;
				ls = l[curr - 1];
				ws = w[curr - 1];
			}
			else {
				gameisright = false;
				break;
			}
		}	
		if(gameisright && lastwin == winner && wt > lt) {
			ps.pb(mp(wt, s));
		}
	}
	cout << ps.size() << "\n";
	int st = ps.size();
	sort(ps.begin(), ps.end());
	for (int i = 0; i < ps.size(); ++i)
		cout << ps[i].first << " " << ps[i].second << "\n";
}