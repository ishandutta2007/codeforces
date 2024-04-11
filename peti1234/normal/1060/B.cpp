#include <bits/stdc++.h>

using namespace std;
long long n;
int s;
int main()
{
    cin >> n;
    while(n>0) {
        if (n%10==9 || n<10) {
            s+=n%10;
            n/=10;
        } else {
            s+=n%10+10;
            n/=10;
            n--;
        }
    }
    cout << s << endl;
    return 0;
}