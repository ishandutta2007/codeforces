#include <bits/stdc++.h>

using namespace std;
map<long long, long long> b;
long long n;
long long t[70001][10];
vector<long long> van;
bool ua(long long x)
{
    for (long long i=0; i<van.size(); i++) {
        if (x==van[i]) {
            return false;
        }
    }
    return true;
}
//long long ks=1000000000;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (long long i=1; i<=n; i++) {
        long long x;
        cin >> x;
        for (long long j=9; j>=1; j--) {
            t[i][j]=x%10;
            x/=10;
        }
    }
    for (long long i=1; i<=n; i++) {
        for (long long j=1; j<=9; j++) {
            for (long long k=1; k<=10-j; k++) {
                long long x=0;
                for (long long p=k; p<=k+j-1; p++) {
                    x*=11;
                    x+=t[i][p];
                    x++;
                }
                //x+=ks;
                if (ua(x)){
                b[x]++;
                van.push_back(x);
                }
            }
        }
        van.clear();
    }
    for (long long i=1; i<=n; i++) {
        for (long long j=1; j<=9; j++) {
            for (long long k=1; k<=10-j; k++) {
                long long x=0;
                for (long long p=k; p<=k+j-1; p++) {
                    x*=11;
                    x+=t[i][p];
                    x++;
                }
               // x+=ks;
                if (b[x]==1) {
                    for (long long p=k; p<=k+j-1; p++) {
                        cout <<t[i][p];
                    }
                    cout << endl;
                    j=100;
                    k=100;
                }
            }
        }
    }
    return 0;
}