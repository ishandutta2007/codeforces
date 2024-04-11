#include <bits/stdc++.h>

using namespace std;
const int c=5005;
long long ans, cnt, db[c], tav[c], kom[c], kis, nagy, ert;
int n, prdb[c], kozos[c];
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=1; i<c; i++) {
        int ii=i, nagy=0, nagydb=0;
        for (int j=2; j<=ii; j++) {
            if (ii%j==0) {
                nagydb=0;
            }
            while (ii%j==0) {
                prdb[j]++;
                nagy=j;
                nagydb++;
                ii/=j;
                cnt++;
            }
        }
        tav[i]=cnt;

        for (int j=nagy; j<=i; j++) {
            kozos[i-1]+=prdb[j];
        }
        kozos[i-1]-=nagydb;
    }
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (x==0) {
            x++;
        }
        db[x]++;
        ans+=tav[x];
    }
    for (int i=1; i<c; i++) {
        kom[i]=kom[i-1]+db[i];
    }
    kis=1, nagy=5000;
    while (kom[nagy]-kom[kis-1]>=(n+1)/2) {
        int mini=tav[kis];
        for (int i=kis; i<nagy; i++) {
            mini=min(mini, kozos[i]);
        }
        ans-=((2*(kom[nagy]-kom[kis-1]))-n)*(mini-ert);
        ert=mini;
        if (kis==nagy) {
            break;
        }
        for (int i=kis; i<nagy; i++) {
            if (kozos[i]==mini) {
                if (kom[i]-kom[kis-1]>=(n+1)/2) {
                    nagy=i;
                    break;
                } else {
                    kis=i+1;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}