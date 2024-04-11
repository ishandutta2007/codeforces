#include <bits/stdc++.h>

using namespace std;
int n;
int mini=INT_MAX;
int t[100002];
int s[100002];
bool lnko()
{

    for (int i=2; i<=mini; i++) {
        int x=1;
        for (int j=1; j<=n; j++) {
            if (s[j]%i!=0) {
                x=0;
                j=1000000;
            }
        }
        if (x==1) {
            return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        s[i]=t[i];
        t[i]=t[i]%2;
    }
    for (int i=1; i<=10; i++) {
        sort(s+1, s+n+1);
        for (int j=n; j>1; j--) {
            s[j]=s[j]-s[j-1];
            if (s[j]>0) {
            mini=min(mini, s[j]);
            }
        }
    }
    //cout << s[1] << " " << s[2];
    sort(s+1, s+n+1);
    if (s[n]==0) {
        cout << "YES" << endl << 0 << endl;
        return 0;
    }
    reverse(s+1, s+n+1);
    if (lnko()) {
        cout << "YES" << endl << 0 << endl;
        return 0;
    }
    int m=0;
    for (int i=1; i<=n; i++) {
        if (t[i]==1) {
            m+=2;
            m-=t[i+1];
            t[i]=0;
            t[i+1]=0;
        }
    }
    cout << "YES" << endl << m << endl;
    return 0;
}