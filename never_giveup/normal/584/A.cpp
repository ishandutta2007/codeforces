#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    int n, t;
    cin >> n >> t;
    if (t == 10){
        if (n == 1)
            cout << -1;
        else{
            cout << 10;
            for(int i = 0; i < n - 2; i++)
                cout << 0;
        }
        return 0;
    }
    cout << t;
    for (int i = 0; i < n - 1; i++)
        cout << 0;
}