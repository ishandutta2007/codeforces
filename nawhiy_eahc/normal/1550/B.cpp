#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, a, b; cin >> n >> a >> b;
        string s; cin >> s;

        int cnt = 0;
        for(int i=1;i<n;i++)
        {
            if(s[i] != s[i-1]) cnt++;
        }

        if(b > 0)
        {
            cout << n * a + n * b << "\n";
        }
        else
        {
            cout << n * a + ((cnt+3)/2) * b << "\n";
        }
    }
}