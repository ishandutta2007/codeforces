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
	int n1, n2;
	cin >> n1 >> n2;
	if(n1 == 1 || n2 == 1)
		cout << n1*n2;
	else if(n1 == 2 || n2 == 2)
	{
		n1 *= n2;
		n2 = n1%8;
		n1 = (n1/8)*4;
		switch(n2)
		{
			case 0:
				break;
			case 2: n1 += 2;
				break;
			case 4:	n1 += 4;
				break;
			case 6: n1 += 4;
				break;
		}
		cout << n1;
	}
	else{
		n1 *= n2;
		n1 ++ ;
		n1 /= 2;
		cout << n1;
	}
}