
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <sstream>

using namespace std;
#define endl '\n'

//vector<int> used(1300, 0);


int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<string,  int> > a;
    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "insert")
        {
            int x;
            cin >> x;
            a.push_back({cmd, x});
            s.insert(x);
        }
        if (cmd == "getMin")
        {
            int x;
            cin >> x;
            while(!s.empty() && *s.begin() < x)
            {
                s.erase(s.begin());
                a.push_back({"removeMin", 123456});
            }
            if (s.empty() || *s.begin()!= x)
            {
                s.insert(x);
                a.push_back({"insert", x});
            }
            a.push_back({cmd, x});
        }
        if (cmd == "removeMin")
        {
            if (s.empty())
            {
                s.insert(0);
                a.push_back({"insert", 0});
            }
            s.erase(s.begin());
            a.push_back({cmd, 123456});
        }
    }
    stringstream out;
    out << a.size() << endl;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i].first == "removeMin")
        {
            out << a[i].first << endl;
        }
        else
        {
            out << a[i].first << " " << a[i].second << endl;
        }
    }
    cout << out.str();
    return 0;

}