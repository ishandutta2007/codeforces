#include <bits/stdc++.h>

using namespace std;
long long a, b;
long long m, sz;
long long x=0, y=10000000000000000;
int t[100001][2];
long long c;
int n;
long long sum;
bool ker(long long z)
{
    long long fi=z/n;
    long long se=z%n;
    if (abs(a+fi*m+t[se][0])+abs(b+fi*sz+t[se][1])<=z) {
        return true;
    }
    return false;
}
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=1; i<=1; i++) {
        long long c, d, e, f;
        cin >> c >> d >> e >> f;
        a=c-e;
        b=d-f;
    }
    swap(a, b);
    cin >> n;
    cin >> s;
    for (int i=0; i<s.size(); i++) {
        if (s[i]=='U') {
            t[i+1][0]=t[i][0]+1;
            t[i+1][1]=t[i][1];
            m++;
        }
        if (s[i]=='D') {
            t[i+1][0]=t[i][0]-1;
            t[i+1][1]=t[i][1];
            m--;
        }
        if (s[i]=='L') {
            t[i+1][0]=t[i][0];
            t[i+1][1]=t[i][1]-1;
            sz--;
        }
        if (s[i]=='R') {
            t[i+1][0]=t[i][0];
            t[i+1][1]=t[i][1]+1;
            sz++;
        }
    }
    bool q=false;
    while(y-x>1) {
        long long z=(x+y)/2;
        if (ker(z)) {
            q=true;
            y=z;
        } else {
            x=z;
        }
    }
    if(!q) {
        cout << -1 << endl;
    } else {
        cout << y << endl;
    }
    return 0;
}