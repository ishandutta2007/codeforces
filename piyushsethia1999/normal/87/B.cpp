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
	cin >> n;
	std::map<string, int> M;
	string op, o1, o2;
	M["void"] = 1;
	for (int i = 0; i < n; ++i)
	{
		cin >> op >> o1;
		if(op == "typedef")
		{
			cin >> o2;
			int ast = 0;
			int amp = 0;
			int siz = o1.size();
			siz--;
			while(o1[siz] == '*') {
				ast++;
				siz--;
			}
			siz = 0;
			while(o1[siz] == '&')
				siz++;
			amp = siz;
			siz = o1.size();
			o1 = o1.substr(amp, siz - amp - ast);
			int c = M[o1];
			if(c == 0 || ((c + ast - amp) <= 0))
				M[o2] = 0;
			else
				M[o2] = c + ast - amp;
		}
		else
		{
			int ast = 0;
			int amp = 0;
			int siz = o1.size();
			siz--;
			while(o1[siz] == '*') {
				ast++;
				siz--;
			}
			siz = 0;
			while(o1[siz] == '&')
				siz++;
			amp = siz;
			siz = o1.size();
			o1 = o1.substr(amp, siz - amp - ast);
			if(M[o1] == 0 || ((M[o1] - amp + ast) <= 0))
				cout << "errtype\n";
			else{
				cout << "void";
				for (int i = 1; i < (M[o1] - amp + ast); ++i)
					cout << "*";
				cout << "\n";
			}
		}
	}
}