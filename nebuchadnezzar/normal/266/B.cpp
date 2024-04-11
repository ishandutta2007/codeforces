#include <cstdio>
#include <iostream>


using namespace std;


int n, t;
string s;



int main()
{
    cin >> n >> t;
    cin >> s;
    for(int i = 0; i < t; ++i)
    {
        int j = 0;
        while(j < n - 1)
        {
            if(s[j] == 'B' && s[j + 1] == 'G')
            {
                s[j] = 'G';
                s[j + 1] = 'B';
                ++j;
            }
            ++j;
        }
    }
    cout << s;
    return 0;

}