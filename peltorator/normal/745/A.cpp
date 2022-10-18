#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;

int main()
{
    string s;
    cin >> s;
    set<string> q;
    for (int i = 0;  i < s.size(); i++)
    {
        string t = "";
        for (int j = i; j < s.size(); j++)
            t += s[j];
        for (int j = 0; j < i; j++)
            t += s[j];
        q.insert(t);
    }
    cout << q.size();
    return 0;
}