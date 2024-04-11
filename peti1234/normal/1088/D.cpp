#include <bits/stdc++.h>

using namespace std;
long long t[31];
long long pl;
long long a, b;
int x=0;
int main()
{
    t[0]=1;
    for (int i=1; i<=30; i++) {
        t[i]=t[i-1]*2;
    }
    cout.flush() << "?" << " "  << 0 << " " << 0 << endl;
    cin >> x;
    for (int i=29; i>=0; i--) {
        int c=0, d=0;
        cout.flush() << "?" << " " << pl+t[i] << " " << 0 << endl;
        cin >> c;
        cout.flush() << "?" << " " << pl << " " << t[i] << endl;
        cin >> d;
        if (c==d) {
            pl+=t[i];
            if (x==1) {
                a+=t[i];
            } else {
                b+=t[i];
            }
            x=c;
        } else {
            if (c==-1) {
                a+=t[i];
                b+=t[i];
            }
        }
    }
    cout.flush() << "!" << " " << a << " " << b << endl;
    return 0;
}