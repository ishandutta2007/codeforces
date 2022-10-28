#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int q;
    for (cin >> q; q--;)
    {
        int n;
        cin >> n;
        int a, b, c;
        cin >> a >> b >> c;
        string s;
        cin >> s;
        
        vector<int> count(26);
        for (char x : s)
        	count[x - 'A']++;
        
        int wins = min(a, count['S' - 'A']) + min(b, count['R' - 'A']) + min(c, count['P' - 'A']);
        
        if (2 * wins < n)
        {
        	cout << "NO" << '\n';continue;
        }
        
        cout << "YES" << '\n';
        string t;
        for (int i = 0; i != n; ++i)
        {
        	if (s[i] == 'S' && a)
        	{
        		t += 'R';
        		a--;
        	}
        	else if (s[i] == 'R' && b)
        	{
        		t += 'P';
        		b--;
        	}
        	else if (s[i] == 'P' && c)
        	{
        		t += 'S';
        		c--;
        	}
        	else
        		t += '_';
        }
        for (int i = 0; i != n; ++i)
        {
        	if (t[i] != '_')
        		continue;
        	
        	if (a)
        	{
        		t[i] = 'R';
        		a--;
        	}
        	else if (b)
        	{
        		t[i] = 'P';
        		b--;
        	}
        	else
        	{
        		t[i] = 'S';
        		c--;
        	}
        }
        cout << t << '\n';
    }
    
    return 0;
}