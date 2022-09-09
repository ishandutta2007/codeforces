#include <cstdio>
#include <iostream>

using namespace std;
const int decdec = 1000000001;

int n, l, r, ll = decdec, rr = -decdec, numl, numr;


int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        //cout << ll << " " << rr << endl;
        cin >> l >> r;
        if(l <= ll && r >= rr)
        {
            ll = l;
            numl = i;
            rr = r;
            numr = i;
        }  
        else if(r > rr)
        {
            rr = r;
            numr = i;
        }
        else if(l < ll)
        {
            ll = l;
            numl = i;
        }
    }                
    if(numr == numl)
    {
        cout << numr + 1;
    }
    else
    {
        cout << "-1";
    }
    return 0;
}