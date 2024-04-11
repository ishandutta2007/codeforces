#include <bits/stdc++.h>

using namespace std;
const int c=300005;
long long t[c][3], n, x, sum;
int lsb(int a) {
    return (a & -a);
}
void add(int a, int b, long long x) {
    while (a<c) {
        t[a][b]+=x;
        a+=lsb(a);
    }
}
long long ask(int a, int b) {
    long long sum=0;
    a=min(a, c-1);
    while (a>0) {
        sum+=t[a][b];
        a-=lsb(a);
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x;

        for (int i=0; i<c; i+=x) {
            long long db=ask(i+x-1, 2)-ask(i-1, 2);
            long long ert=ask(i+x-1, 1)-ask(i-1, 1);
            sum+=ert-db*i;
        }

        sum+=x*(i-1)-ask(x, 0);

        cout << sum << "\n";
        for (int i=x; i<c; i+=x) {
            add(i, 0, x);
        }
        add(x, 1, x);
        add(x, 2, 1);

    }
    return 0;
}