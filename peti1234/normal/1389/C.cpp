#include <bits/stdc++.h>

using namespace std;
int w, n, maxi;
string s;
int main()
{
    cin >> w;
    while(w--) {
        cin >> s, n=s.size(), maxi=0;
        for (int a=0; a<=9; a++) for (int b=0; b<=9; b++) {
            int db=0;
            for (int i=0; i<n; i++) {
                int x=s[i]-'0';
                if ((db%2==0 && x==a) || (db%2 && x==b)) db++;
            }
            if (a!=b && db%2) db--;
            maxi=max(maxi, db);
        }
        cout << n-maxi << "\n";
    }
    return 0;
}