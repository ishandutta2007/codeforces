#include <bits/stdc++.h>

using namespace std;
vector<int> a, b, c;
int t[1501];
int n, k, x, y, z, maxi;
string s;
bool out(int a, int b, int c)
{
    cout.flush() << '?' << " " << a << " "  << b << " " << c << endl;
    cin >> s;
    return s=="Yes";
}
void rsa() {
    random_shuffle(a.begin(), a.end()); }
void rsb() {
    random_shuffle(b.begin(), b.end()); }
void rsc() {
    random_shuffle(c.begin(), c.end()); }
void fin(int a) {
    cout.flush() << '!' << " "  << a << endl; }
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        a.push_back(i);
        b.push_back(i);
        c.push_back(i);
    }
    rsa(), rsb(), rsb(), rsc(), rsc(), rsc();
    int w=50;
    if (n<200) {
        w=42;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=w; j++) {
            while(a[x]==i) {
                x++, x%=n;
            }
            while(a[x]==i) {
                x++, x%=n;
            }
            while(b[y]==i) {
                y++, y%=n;
            }
            while(c[z]==i) {
                z++, z%=n;
            }
            int p=a[x], q=b[y], r=c[z];
            int s=out(p, i, q)+out(p, i, r)+out(q, i, r);
            if (s==3 && k==2) {
                t[i]-=1000;
                break;
            }
            if (j==9 && t[i]<=2) {
                t[i]-=1000;
                break;
            }
            if (j==3 && t[i]==0 && k>2) {
                t[i]-=1000;
                break;
            }
            t[i]+=s;
            x++, y++, z++;
            x%=n,z%=n, y%=n;
            if (n<=30 && n%j==0) {
                rsa(), rsa(), rsb();
            }
        }
        rsa(), rsb(), rsb(), rsc(), rsc(), rsc(), rsc();
    }
    for (int i=1; i<=n; i++) {
        if (t[i]>t[maxi]) {
            maxi=i;
        }
    }
    fin(maxi);
    return 0;
}