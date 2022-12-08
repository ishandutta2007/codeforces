				/* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

struct team{
	string name;
	int scr, x, y;
	team(){
		scr = x = y = 0;
	}
	bool operator < (const team &a) const{
		if(scr != a.scr)
			return scr > a.scr;
		if(x - y != a.x - a.y)
			return (x - y) > (a.x - a.y);
		return x > a.x;
	}
};

int n;
team tm[60];
map <string, int> mp;
string res[60];

int main(){	
	cin >> n;
	string str;
	for(int i = 0; i < n; i++){
		cin >> tm[i].name;
		mp[tm[i].name] = i;
	}
	getline(cin, str);
	for(int i = 0; i < n * (n - 1) / 2; i++){
		getline(cin, str);
		for(int j = 0; j < str.length(); j++)
			if(str[j] == '-' || str[j] == ':')
				str[j] = ' ';
		istringstream sin(str);
		string n1, n2;
		int g1, g2;
		sin >> n1 >> n2 >> g1 >> g2;
		int a1 = mp[n1], a2 = mp[n2];
		tm[a1].x += g1, tm[a1].y += g2;
		tm[a2].x += g2, tm[a2].y += g1;
		if(g1 > g2) tm[a1].scr += 3;
		if(g1 < g2) tm[a2].scr += 3;
		if(g1 == g2) tm[a1].scr += 1, tm[a2].scr += 1;
	}
	sort(tm, tm + n);
	for(int i = 0; i < n / 2; i++)
		res[i] = tm[i].name;
	sort(res, res + n / 2);
	for(int i = 0; i < n / 2; i++)
		cout << res[i] << endl;
	return 0;
}