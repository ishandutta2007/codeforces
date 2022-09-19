#include <bits/stdc++.h>

using namespace std;
long long  n, m;
long long os=1;
long long kor=1;
int main()
{
    cin >> n >> m;
    if (m>n/2) {
        m=n-m;
    }
    for (int i=1; i<=n; i++) {
        if ((m*(i-1))%n>(m*i)%n) {
            kor++;
        }
        if ((m*(i-2))%n>m*(i-1)%n) {
            kor++;
        }

        os+=kor;
        if (i==n) {
            os--;
        }
        cout << os << " ";
    }
    return 0;
}