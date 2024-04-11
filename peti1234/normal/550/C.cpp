#include <bits/stdc++.h>

using namespace std;
int n;
string s;
void ans(int a) {
    cout << "YES\n";
    cout << a << "\n";
}
int main()
{
    cin >> s, n=s.size();
    for (int i=0; i<n; i++) {
        if (s[i]=='8') {
            ans(8);
            return 0;
        }
        if (s[i]=='0') {
            ans(0);
            return 0;
        }
    }
    for (int i=16; i<100; i+=8) {
        int h=0, x=i%10, y=i/10;
        for (int i=0; i<n; i++) {
            if ((h==0 && s[i]-'0'==y) || (h==1 && s[i]-'0'==x)) h++;
        }
        if (h==2) {
            ans(i);
            return 0;
        }
    }
    for (int i=104; i<1000; i+=8) {
        int a=i/100, c=i%10, b=(i-100*a-c)/10, h=0;
        for (int i=0; i<n; i++) {
            int x=s[i]-'0';
            if ((h==0 && x==a) || (h==1 && x==b) || (h==2 && x==c)) h++;
        }
        if (h==3) {
            ans(i);
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}