#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <limits>
#include <tuple>
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m1 = 0, m2 = 0, n1 = 0, n2 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i % 2 == 1)
        {if (s[i] == 'r')
            m1++;
        else
            n1++;}
        else{
                if (s[i] == 'b')
            m2++;
        else
            n2++;
        }
    }
    cout << min(min(m1, m2) + abs(m1 - m2), min(n2, n1) + abs(n2 - n1));
	return 0;
}