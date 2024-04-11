#include <bits/stdc++.h>

using namespace std;
bool v[27];
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, k;
        cin >> n >> k;
        set<char> p;
        string s;
        cin >> s;
        for (int i=0; i<n; i++) {
            int x=s[i]-'a';
            while (x>0 && !v[x] && k) {
                v[x]=1, k--, x--;
            }
            x=s[i]-'a';
            while (v[x]) x--;
            char p='a'+x;
            s[i]=p;
        }

        cout << s << "\n";



        for (int i=0; i<27; i++) {
            v[i]=0;
        }
    }
    return 0;
}