#include <bits/stdc++.h>

using namespace std;
long long fib[105];
int main()
{
    fib[1]=1, fib[2]=2;
    for (int i=3; i<=90; i++) {
        fib[i]=fib[i-1]+fib[i-2];
    }
    int w;
    cin >> w;
    while (w--) {
        long long x;
        cin >> x;
        vector<int> sz;
        for (int i=90; i>=1; i--) {
            if (fib[i]<=x) {
                sz.push_back(i);
                x-=fib[i];
            }
        }
        sz.push_back(0);
        reverse(sz.begin(), sz.end());
        long long a=1, b=0;
        for (int i=1; i<sz.size(); i++) {
            int dif=sz[i]-sz[i-1];
            long long c=a+b, d=(dif-1)/2*(a+b)+(dif-1)%2*b;
            a=c, b=d;
        }
        cout << a+b << "\n";
    }
    return 0;
}