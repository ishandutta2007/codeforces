#include <bits/stdc++.h>
#define lsb(a) ((a) & -(a))
using namespace std;
const int c=200002;
long long t[c], k[c], u[c], n;
bool v[c];
void add(long long a, long long b) {
    while(a<=n) {
        t[a]+=b;
        a+=lsb(a);
    }
}
long long ans(long long a) {
    long long sum=0;
    while(a>0) {
        sum+=t[a];
        a-=lsb(a);
    }
    return sum;
}
int kov(int a) {
    if (!v[a]) {
        return a;
    }
    int x=kov(u[a]);
    u[a]=x;
    return x;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        u[i]=i+1;
        add(i, i-1);
        cin >> k[i];
    }
    for (int i=n; i>=1; i--) {
        long long x=0, y=n;
        while(y-x>1) {
            long long z=(x+y)/2;
            if (ans(z)>=k[i]) {
                y=z;
            } else {
                x=z;
            }
        }
        y=kov(y);
        v[y]=true;
        k[i]=y;
        add(y+1, -y);
    }
    for (int i=1; i<=n; i++) {
        cout << k[i] << " ";
    }
    return 0;
}