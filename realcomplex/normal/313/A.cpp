#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second

int main()
{
    int n;
    cin >> n;
    if(n > 0){
        cout << n;
    }
    else{
        n = abs(n);
        int f,s;
        s = n%10;
        f = (n%100)/10;
        n = (n/100)*10;
        n += min(f,s);
        if(n != 0){
            cout << "-";
        }

        cout << n;
    }
    return 0;
}