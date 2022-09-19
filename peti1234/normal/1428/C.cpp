#include <bits/stdc++.h>

using namespace std;
const int c=300002;
int w, n, maxi, db, bc;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> s, maxi=0, db=0, bc=0, n=s.size();
        for (int i=0; i<n; i++) {
            if (s[i]=='A') db--;
            else db++, bc++, maxi=max(maxi, db);
        }
        cout << n-((bc-maxi)*2+maxi-maxi%2) << "\n";
    }
    return 0;
}