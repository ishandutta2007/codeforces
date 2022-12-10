#include <bits/stdc++.h>

using namespace std;

int c[26];

int main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
        c[s[i] - 'a']++;
    int x = 0;
    for(int i = 0; i < 26; i++)
        if(c[i] & 1)
            x++;
    if(x == 0)
		cout << "First" << endl;
	else
    	cout << ((x & 1) ? "First" : "Second") << endl;
    return 0;
}