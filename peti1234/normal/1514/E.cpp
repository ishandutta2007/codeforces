#include <bits/stdc++.h>

using namespace std;
const int c=102;
int w, n, t[c], ki[c];
bool v[c][c];
int holvan(int a) {
    if (!ki[a]) {
        return a;
    }
    return ki[a]=holvan(ki[a]);
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
    }
}
bool kerd(int a, int b) {
    cout.flush() << 1 << " " << a-1 << " " << b-1 << "\n";
    bool ans;
    cin >> ans;
    return ans;
}
bool kerd2(int a, int b) {
    cout.flush() << 2 << " " << t[a]-1 << " " << n-b+1 << " ";
    for (int i=b; i<=n; i++) {
        cout << t[i]-1 << " ";
    }
    cout.flush() << "\n";
    bool ans;
    cin >> ans;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            t[i]=0, ki[i]=0;
            for (int j=1; j<=n; j++) {
                v[i][j]=0;
            }
        }
        for (int i=1; i<=n; i++) {
            int lo=1, hi=i, mid;
            while (hi>lo) {
                mid=(hi+lo)/2;
                if (kerd(i, t[mid])) {
                    lo=mid+1;
                } else {
                    hi=mid;
                }
            }
            for (int j=i-1; j>=lo; j--) {
                t[j+1]=t[j];
            }
            t[lo]=i;
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<i; j++) {
                v[t[i]][t[j]]=1;
            }
        }
        int pos=2;
        for (int i=1; i<=n; i++) {
            pos=max(pos, i+1);
            while (pos<=n && kerd2(i, pos)) {
                unio(i, pos);
                pos++;
            }
        }
        cout << 3 << "\n";
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (holvan(i)==holvan(j)) {
                    v[t[i]][t[j]]=1;
                }
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                cout << v[i][j];
            }
            cout << "\n";
        }
        bool ans;
        cin >> ans;
    }
    return 0;
}