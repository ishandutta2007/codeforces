#include <bits/stdc++.h>

using namespace std;
int n;
int t[200001];
int k[200001];
long long ok[200001];
long long tel[200002];
long long pl[200002];
long long os(int a, int b)
{
    if (a==0) {
        return ok[b];
    }
    return ok[b]-ok[a-1];
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> k[i];
        ok[i]=ok[i-1]+k[i];
    }
    for (int i=1; i<=n; i++) {
        int x=i-1, y=n+1;
        while(y-x>1) {
            int p=(x+y)/2;
            if (os(i, p)<t[i]) {
                x=p;
            } else {
                y=p;
            }
        }
        tel[i]++;
        tel[y]--;
        if (x==0) {
            pl[y]+=t[i];
        }
        else {
        pl[y]+=t[i]-(os(i, x));
        }
    }
    long long p=0;
    for (int i=1; i<=n; i++) {
        p+=tel[i];
        cout << (long long)k[i]*p+pl[i] << " ";
    }
    return 0;
}