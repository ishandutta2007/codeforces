#include <iostream>
#include <string>

using namespace std;

const int inf = 1e9 + 7;

int main ()
{
    string str;
    
    cin >> str;
    
    long long ans = 0, w = 0;

    while (!str.empty ())
    {
        if (str.back () == 'a')
        {
            ans += w;
            w = (w << 1) % inf;
        }
        else
            w++;
            
        str.pop_back ();
    }
        
    cout << ans % inf << endl;

    return 0;
}