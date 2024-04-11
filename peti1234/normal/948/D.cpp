#include <bits/stdc++.h>

using namespace std;
int n;
int t[300001];
int k[36000000][3];
vector<int> s;
int m=3;
void ker(int x)
{
    int s=x;
    int d=0;
    int c=0;
    for (int i=29; i>=0; i--) {
        int z=x>=1<<i;
        if (z==1) {
            x-=1<<i;
        }
        if (k[c][z]==0 || k[k[c][z]][2]==0) {
            z=1-z;
        }
        c=k[c][z];
        k[c][2]--;
        d+=z*1<<i;
    }
    cout << (d^s) << " ";
}
void p(int x)
{
    int c=0;
    for (int i=29; i>=0; i--) {
        int z=x>=1<<i;
        if (z==1) x-=1<<i;
            if (k[c][z]==0) {
                k[c][z]=m;
                k[m][2]++;
                c=m;
                m++;
            } else {
                int q=k[c][z];
                k[q][2]++;
                c=q;
            }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    k[0][0]=1;
    k[0][1]=2;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        p(x);
    }
    for (int i=1; i<=n; i++) {
        ker(t[i]);
    }
    return 0;
}