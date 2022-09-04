#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int now = 0, beg = 0, ans = 0;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        if (x == 0)
            now++;
        else{
            if (beg == 0)
                beg = 1, ans += now;
            else
                if (now > 1)
                    ans += now;
            now = 0;
        }
    }
    ans += now;
    cout << n - ans;
}