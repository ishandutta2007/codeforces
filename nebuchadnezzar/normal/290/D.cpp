#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string s;
int x;

char b(char c)
{
    if(int(c) <= int('z') && int(c) >= int('a'))
    {
        return char(int(c) + int('A') - int('a'));
    }
    return c;
}
char sm(char c)
{
    if(int(c) <= int('Z') && int(c) >= int('A'))
    {
        return char(int(c) + int('a') - int('A'));
    }
    return c;
}


int main()
{
    cin >> s;
    cin >> x;
    //s = 'a' + s;
    int a;
    string ans;
    for(int i = 0; i < s.length(); ++i)
    {
        a = s[i];
        //cout << a << endl;
        if(int(sm(a)) < x + 97)
        {
            ans += b(a);  
        }  
        else
        {
            ans += sm(a);
        }
    }
    cout << ans;


    return 0;
}