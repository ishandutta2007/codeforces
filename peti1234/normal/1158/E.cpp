#include <bits/stdc++.h>

using namespace std;
int n, m=512, t[1001], k[1001], ert[1001], v[1001];
bool h[1001];
vector<int> sz[1004];
void kj() {
    cout.flush() << "?" << " ";
}
int ch() {
    char c;
    cin >> c;
    if (c=='1') return 1;
    return 0;
}
bool ek(int a) {
    kj();
    cout.flush() << a << " ";
    for (int i=2; i<=n; i++) cout.flush() << 0 << " ";
    cout.flush() << "\n";
    int db=0;
    for (int i=1; i<=n; i++) {
        int x=ch();
        if (i!=1) {
            if (x==0) db++, k[i]=max(k[i], a+1);
            else v[i]=min(v[i], a);
            if (!h[i] && k[i]==v[i]) h[i]=true, sz[k[i]].push_back(i);
        }
    }
    return (db>0);
}
void kerd(int b, int c, int a) {
    kj();
    for (int i=1; i<=n; i++) t[i]=0;
    for (int i=c; i<=n; i+=b) for (int j=0; j<sz[i].size(); j++) {
        int x=sz[i][j];
        t[x]=a;
    }
    for (int i=1; i<=n; i++) cout.flush() << t[i] << " ";
    cout.flush() << "\n";
    for (int i=1; i<=n; i++) {
        int x=ch();
        if (!h[i]) {
            int mod=k[i]%b;
            if (mod<b/2==(c==0)) {
                int p=k[i]-k[i]%b+c;
                if (x) v[i]=min(v[i], p+a);
                else k[i]=max(k[i], p+a+1);
            }
            if (k[i]==v[i]) h[i]=true, sz[k[i]].push_back(i);
        }
    }
}
void l(int a, int b)
{
    for (int i=1; i<=n; i++) t[i]=0;
    int db=0;
    for (int i=a;; i+=3) {
        if (sz[i].size()==0) break;
        for (int j=0; j<sz[i].size(); j++) {
            if ((j%b)>=(b/2)) t[sz[i][j]]=1, db++;
        }
    }
    if (db==0) return;
    kj();
    for (int i=1; i<=n; i++) cout.flush() << t[i] << " ";
    cout.flush() << "\n";
    for (int i=1; i<=n; i++) {
        int x=ch();
        if ((k[i]%3)==(a+1)%3 && x) ert[i]+=b/2;
    }
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    k[1]=0, v[1]=0, h[1]=true, sz[0].push_back(1);
    for (int i=2; i<=n; i++) k[i]=1, v[i]=n-1;
    while(m>=n) m/=2;
    while(!ek(m)) m/=2;
    if (m==0) {
        cout.flush() << "!" << "\n";
        for (int i=2; i<=n; i++) cout.flush() << i << " " << 1 << "\n";
        return 0;
    }
    ek(m-1);
    while(m/2>=1) {
        kerd(2*m, 0, m/2), kerd(2*m, 0, m/2-1);
        kerd(2*m, m, m/2), kerd(2*m, m, m/2-1);
        m/=2;
    }
    for (int i=0; i<=2; i++) for (int j=2; j<=2*n; j*=2) l(i, j);
    cout.flush() << "!" << "\n";
    for (int i=2; i<=n; i++) cout.flush() << i << " " << sz[k[i]-1][ert[i]] << "\n";
    return 0;
}