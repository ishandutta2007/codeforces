#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>

using namespace std;
typedef long long ll;






int main()
{
	ll k, n, m,x,y;
	int c1, c2, c3, c4, c5, c6;
	string a,b,c;
	std::cin >> a >> b >> c;

	std::vector<int> Ma;
	std::vector<int> Mb;
	std::vector<int> Mc;

	int la = a.length();
	int lb = b.length();
	int lc = c.length();

	for (c1 = 0; c1 < 26; c1++){

		Ma.push_back(0);
		Mb.push_back(0);
		Mc.push_back(0);
		
	}

	for (c1 = 0; c1 < la; c1++){
	
		Ma[int(a[c1])-97]++;
	
	}

	for (c1 = 0; c1 < lb; c1++){

		Mb[int(b[c1]) - 97]++;

	}

	for (c1 = 0; c1 < lc; c1++){

		Mc[int(c[c1]) - 97]++;

	}
	int fail = 0;
	c2 = 1;
	int m2 = 0;
	int m3 = 0;
	int ans = 0;
	for (c2 = 0; c2 <= la;c2++){

		for (c1 = 0; c1 < 26; c1++){

			if (Mb[c1] * c2 > Ma[c1]){ fail = 1; }
		}
		if (fail == 1){break; }

		c3 = 9999999;
		for (c1 = 0; c1 < 26; c1++){
			//if (char(c1 + 97) == 'a' || char(c1 + 97) == 'c'){ cout << Mc[c1] << " " << floor((Ma[c1] - c2*Mb[c1]) / Mc[c1]) << " " << c2 << "\n"; }

			if (Mc[c1] != 0){
				if (floor((Ma[c1] - c2*Mb[c1]) / Mc[c1]) < c3){ c3 = floor((Ma[c1] - c2*Mb[c1]) / Mc[c1]); }

			}
		}
		if (c3 == 9999999 || c3<0){ c3 = 0; }

		if (c2 + c3 > ans){ ans = c2 + c3; m2 = c2; m3 = c3; }


	}
	//cout << m2 << " " << m3 << "\n";

	string s1 = "";
	for (c1 = 0; c1 < m2; c1++){ s1 += b; }
	for (c1 = 0; c1 < m3; c1++){ s1 += c; }
	for (c1 = 0; c1 < 26; c1++){

		for (c4 = 0; c4 < Ma[c1] - Mc[c1] * m3 - Mb[c1] * m2; c4++){ s1 += char(c1 + 97); }


	}

	std::cout << s1 << "\n";

	return 0;
}