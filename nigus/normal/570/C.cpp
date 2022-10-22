#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>

using namespace std;
typedef long long ll;

ll big = 1000000007ll;

int main()
{
	ll k, z, m,n, a, b, ans,q;
	int c1, c2, c3, c4, c5, c6, c7;

	std::cin >> n >> q;
	string s="1";
	string t;
	char c;
	std::cin >> t;
	s+=t;
	s+='1';
	ans=0;

	for(c1=1;c1<=n;c1++)
    {

        if(s[c1] == '.' &&s[c1-1] == '.'){ans++;}

    }



	for(c1=0;c1<q;c1++)
    {
        std::cin >> a;
        std::cin >> c;


        if(s[a] == '.' && c != '.')
        {
            if(s[a-1] == '.'){ans--;}
            if(s[a+1] == '.'){ans--;}
            s[a] = c;


        }

        if(s[a] != '.' && c == '.')
        {
            if(s[a-1] == '.'){ans++;}
            if(s[a+1] == '.'){ans++;}
            s[a] = c;

        }

        std::cout << ans << "\n";
    }


	return 0;
}