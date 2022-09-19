#include <bits/stdc++.h>

using namespace std;
long long t[5000002];
long long k[5000001];
long long l[5000001];
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    t[1]=1;
    for (int i=2; i<=c-b+1; i++) {
        t[i]=t[i-1]*a%1000000007;
    }
    for (int i=2; i<=c; i++) {
        if (l[i]==0) {
            for (int j=i; j<=c; j+=i) {
                if (l[j]==0) {
                    l[j]=i;
                }
            }
        }
    }
    for (int i=2; i<=c; i++) {
        k[i]=(k[i/l[i]]+(i*(l[i]-1)/2))%1000000007;
    }
    long long m=0;
    for (int i=0; i<=c-b; i++) {
        m+=t[i+1]*k[b+i];
        m%=1000000007;
    }
    cout << m << endl;
    for (int i=1; i<=10; i++) {
        //cout << i << " " << t[i] << " " << k[i] << " " << l[i] << endl;
    }
    return 0;
}