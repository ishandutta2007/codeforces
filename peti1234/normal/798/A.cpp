#include <bits/stdc++.h>

using namespace std;
string s;
int k;
int p;
int mennyi()
{
    int x=0;
    for (int i=0; i<k; i++) {
        if (s[i]!=s[k-1-i]) {
            x++;
        }
    }
    x/=2;
    return x;
}
int main()
{
    cin >> s;
    k=s.size();
    p=mennyi();
    if (p>1 || (p==0 && k%2==0)) {
        cout << "NO";
        return 0;
    }
    cout << "YES";

    return 0;
}