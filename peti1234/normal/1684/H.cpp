#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
int w, n, t[c], cnt, kezd, veg;
bool v[c];
string s;
void pr() {
    int db=0;
    for (int i=1; i<=n; i++) {
        db+=v[i];
    }
    cout << db << "\n";
    int ut=1;
    for (int i=1; i<=n; i++) {
        if (v[i]) {
            cout << ut << " " << i << "\n";
            ut=i+1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s;
        n=s.size();

        cnt=0, kezd=0, veg=0;
        for (int i=1; i<=n; i++) {
            t[i]=0, v[i]=0;
        }
        for (int i=1; i<=n; i++) {
            t[i]=(s[i-1]=='1');
            if (t[i]) {
                cnt++;
                if (!kezd) kezd=i;
                veg=i;
            }
        }
        if (!cnt) {
            cout << -1 << "\n";
            continue;
        }
        if (cnt==veg-kezd+1) {
            v[kezd]=1, v[veg]=1, v[n]=1;
            pr();
            continue;
        }
        for (int i=1; i<=n; i++) {
            v[i]=1;
        }
        if (cnt==5) {
            for (int i=1; i<=n-2; i++) {
                if (t[i]==1 && t[i+1]==0) {
                    v[i]=0, v[i+1]=0;
                    break;
                }
            }
            pr();
            continue;
        }
        int po=1, dif;
        while (po<cnt) po*=2;
        dif=po-cnt;
        int ut=t[1];
        for (int i=1; i<n; i++) {
            if (dif>=ut) {
                v[i]=0;
                dif-=ut;
                ut=2*ut+t[i+1];
            } else {
                ut=t[i+1];
            }
        }
        pr();
    }
    return 0;
}
/*
1
111101
*/