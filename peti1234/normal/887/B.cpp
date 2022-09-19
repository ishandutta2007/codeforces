#include <bits/stdc++.h>

using namespace std;
bool v[1001];
int t[21];
int k[11];
bool p[11];
int n;
int main()
{
    v[0]=true;
    cin >> n;
    int q=6*n;
    for (int i=1; i<=q; i++) {
        cin >> t[i];
        if (p[t[i]]==false) {
            k[t[i]]++;
            p[t[i]]=true;
        }

        if (i%6==0) {
            for (int j=0; j<=10; j++) {
                p[j]=false;
            }
        }
    }
    k[10]=k[0];
    for (int i=1; i<=10; i++) {
        if (k[i]==0) {
            cout << i-1 << endl;
            return 0;
        }

    }
    for (int i=10; i<=99; i++) {
        if (i%11==0) {
            if (k[i/11]<2) {
                cout << i-1 << endl;
                return 0;
            }
        } else {
            int a=i/10;
            int b=i%10;
            if (k[a]+k[b]==2) {
                int aa=0;
                int bb=0;
                for (int i=1; i<=q; i++) {
                    if (t[i]==a) {
                        aa=i-1;
                    }
                    if (t[i]==b) {
                        bb=i-1;
                    }
                }

                if (aa/6==bb/6) {
                    cout << i-1 << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}