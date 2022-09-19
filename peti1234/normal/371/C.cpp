#include <bits/stdc++.h>

using namespace std;
long long da, db, dc, va, vb, vc, pa, pb, pc, f, x, y=1e13, o=0;
string s;
int main()
{
    cin >> s;
    for (int i=0; i<s.size(); i++) {
        if (s[i]=='B') da++;
        if (s[i]=='S') db++;
        if (s[i]=='C') dc++;
    }
    cin >> va >> vb >> vc >> pa >> pb >> pc >> f;
    while(y-x>1) {
        long long z=(x+y)/2, sum=0;
        sum+=max(o, (da*z-va)*pa);
        sum+=max(o, (db*z-vb)*pb);
        sum+=max(o, (dc*z-vc)*pc);
        if (sum>f) y=z;
        else x=z;
    }
    cout << x << "\n";
    return 0;
}