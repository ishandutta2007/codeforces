#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string s;
vector <string> a;
int n;


int main() {
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //
        while (cin >> s) {
                int start = 0;
                for (int i = 0; i < s.size(); i++)
                        if (s[i] == ',' || s[i] == '.' || s[i] == '?' || s[i] == '!') {
                                string s1 = s.substr(start, i-start);
                                if (s1 != "") a.push_back(s1);
                                s1 = s.substr(i, 1);
                                a.push_back(s1);
                                start = i + 1;
                        }
                if (start < s.size())
                        a.push_back(s.substr(start, s.size()-start+1));
        }       
        //
        for (int i = 0; i < a.size(); i++)
                if (i == 0) cout << a[i]; else
                        if (a[i] == "," || a[i] == "." || a[i] == "?" || a[i]=="!") cout << a[i]; else
                                cout << " " << a[i];
        //
        return 0;
};