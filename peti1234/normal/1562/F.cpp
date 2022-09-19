#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long kerd(int a, int b) {
    cout << "? " << a << " " << b;
    cout.flush() << endl;
    long long x;
    cin >> x;
    return x;
}
int w, n, pr[c];
long long ans[c];
int vel() {
    long long a=rand(), b=rand(), c=rand();
    return (a*b+c)%(n-1)+2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    srand(time(0));
    pr[1]=1;
    for (int i=2; i<c; i++) {
        if (!pr[i]) {
            for (int j=i; j<c; j+=i) {
                pr[j]=max(pr[j], i);
            }
        }
    }

    cin >> w;
    while (w--) {
        cin >> n;
        if (n<=100) {
            for (int i=1; i<=n; i++) {
                ans[i]=0;
            }
            for (int i=1; i<=n; i++) {
                long long res=0;
                for (int j=i+1; j<=n; j++) {
                    long long x=kerd(i, j);
                    ans[i]=__gcd(ans[i], x);
                    ans[j]=__gcd(ans[j], x);
                }
            }
            int maxi=0;
            for (int i=1; i<=3; i++) {
                if (ans[i]>ans[maxi]) {
                    maxi=i;
                }
            }
            if (n==3 && ans[maxi]%2==0) {
                ans[maxi]/=2;
            }

        } else {
            long long e=0;
            for (int i=1; i<=200; i++) {
                e=__gcd(e, kerd(1, vel()));
            }
            long long pos=1, maxi=pr[e];
            for (int i=1; i<=4800; i++) {
                int ki=vel();
                long long s=kerd(1, ki)/e;
                if (s<c && pr[s]>maxi) {
                    maxi=pr[s];
                    pos=ki;
                }
            }
            ans[pos]=maxi;
            for (int i=1; i<=n; i++) {
                if (i!=pos) {
                    ans[i]=kerd(pos, i)/maxi;
                }
            }
        }
        cout << "! ";
        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}