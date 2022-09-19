#include <bits/stdc++.h>

using namespace std;
const int c=5002;
int n, t[c], x[c], kezd[c], veg[c];
bool jo[c];
int tav(int a, int b) {
    return abs(x[a]-x[b]);
}
void add(int a, int b, int c) {
    jo[a]=1, kezd[a]=min(kezd[a], b), veg[a]=max(veg[a], c);
}
void ut(int ido, int hely, int kov, int cl) {
    if (kov>n) return;
    int dist=abs(hely-x[kov]), ert=t[kov]-ido, dif=(ert-dist)/2;
    if (ert>=dist) {
        add(kov, max(x[kov]-t[kov]+cl, min(hely, x[kov])-dif), min(x[kov]+t[kov]-cl, max(hely, x[kov])+dif));
        ut(max(cl, ido+dist), x[kov], kov+1, t[kov]);
    }
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i] >> x[i], kezd[i]=x[i], veg[i]=x[i];
    jo[0]=1;
    for (int i=0; i<n; i++) {
        if (jo[i]) {
            int s=t[i+1]-t[i]-tav(i, i+1);
            if (s>=0) {
                add(i+1, min(kezd[i], min(x[i], x[i+1])-s/2), max(veg[i], max(x[i], x[i+1])+s/2));
                ut(t[i]+tav(i, i+1), x[i+1], i+2, t[i+1]);
            }
            if (kezd[i]<=x[i+1] && x[i+1]<=veg[i]) ut(t[i], x[i], i+2, t[i+1]);
        }
    }
    if (jo[n] || (jo[n-1] && kezd[n-1]<=x[n] && x[n]<=veg[n-1])) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}