#include <bits/stdc++.h>

using namespace std;
bool ask(int a, int b) {
    cout.flush() << "? " << a << " " << b << "\n";
    char c;
    cin >> c;
    return (c=='y');
}
int main()
{
    string s;
    while (true) {
        cin >> s;
        if (s=="end") break;
        int a=0, b=1;
        while (ask(a, b)) {
            a=b, b=2*b;
        }
        int lo=a, hi=b, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            if (ask(a, mid)) lo=mid;
            else hi=mid;
        }
        cout.flush() << "! " << hi << "\n";
    }
    return 0;
}