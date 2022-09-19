#include <bits/stdc++.h>

using namespace std;
const int c=100000;
int w, n, x, sum, kom[10*c];
long long db;
string s;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> s, sum=c, db=0;
        for (int i=c-n; i<c+9*n; i++) kom[i]=0;
        kom[c]++;
        for (int i=0; i<n; i++) {
            x=s[i]-'1';
            sum+=x;
            db+=kom[sum], kom[sum]++;
        }
        cout << db << "\n";
    }
    return 0;
}