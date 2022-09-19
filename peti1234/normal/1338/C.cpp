#include <bits/stdc++.h>

using namespace std;
int w;
long long n, alap, s, t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        alap=1, s=1, t=n%3;
        if (!t) t=3;
        while(alap*4<=n) alap*=4;
        n-=alap, n/=3, alap*=t;
        if (t==1) alap+=n;
        if (t==2) {
            while(n>0) {
                if (n%4==1) alap+=2*s;
                if (n%4==2) alap+=3*s;
                if (n%4==3) alap+=s;
                s*=4, n/=4;
            }
        }
        if (t==3) {
            while(n>0) {
                if (n%4==1) alap+=3*s;
                if (n%4==2) alap+=s;
                if (n%4==3) alap+=2*s;
                s*=4, n/=4;
            }
        }
        cout << alap << "\n";
    }
    return 0;
}
// Meg lehetett sejteni a sorozatot, utna nem volt nehz.