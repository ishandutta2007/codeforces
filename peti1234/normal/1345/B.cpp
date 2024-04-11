#include <bits/stdc++.h>

using namespace std;
const int c=100001;
long long p[c], w, n, db;
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=1; i<=c; i++) p[i]=p[i-1]+3*i-1;
    cin >> w;
    while(w--) {
        cin >> n, db=0;
        while(n>1) {
            int l=1, h=c;
            while(h-l>1) {
                long long m=(h+l)/2;
                if (n>=p[m]) l=m;
                else h=m;
            }
            n-=p[l], db++;
        }
        cout << db << "\n";
    }
    return 0;
}