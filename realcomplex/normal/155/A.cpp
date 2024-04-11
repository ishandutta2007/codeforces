#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int sk;
    cin >> sk;
    int mx,mi;
    mx = sk;
    mi = sk;
    int t = 0;
    for(int i = 1;i<n;i++){
        cin >> sk;
        if(sk > mx){
            mx = sk;
            t++;
        }
        if(sk < mi){
            mi = sk;
            t++;
        }
    }
    cout << t;
    return 0;
}