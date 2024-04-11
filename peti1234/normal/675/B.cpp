#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    swap (c, d);
    long long db=0;
    for (int x=1; x<n+1; x++){
        if ((x+b-d>0) && (x+b-d<n+1))
            if ((x+a-c>0) && (x+a-c<n+1))
                if ((x+a+b-c-d>0) && (x+a+b-c-d<n+1)){
                    db+=n;
                }
    }
    cout << db << endl;
    return 0;
}