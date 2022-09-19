#include <bits/stdc++.h>

using namespace std;
int n, x, ert, pos, spec, spec2, ut;
bool v[1005], fix[1005];
bool test=0;
int cnt=0;
int pr() {
    cnt++;
    for (int i=1; i<=n; i++) {
        cout << (v[i]==0 ? 'F' : 'T');
    }
    cout.flush() << endl;
    int ans;
    if (test) {
        int cnt=0;
        for (int i=1; i<=n; i++) if (v[i]==0) cnt++;
        ans=cnt;
    }
    else cin >> ans;
    //if (test) cout << "valasz " << ans << "\n";
    if (ans==n) {
        if (test) {
            cout << cnt << "\n";
            cout << "sikerult\n";
        }
        exit(0);
    }
    return ans;
}
void f(int x) {
    v[x]=!v[x];
}
void s(int x) {
    fix[x]=!fix[x];
}
int main()
{
    srand(time(0));
    cin >> n;
    for (int i=1; i<=n; i++) {
        v[i]=rand()%2;
        fix[i]=v[i];
    }
    x=pr();
    while (pos<n) {
        //cout << "fontos " << pos << " " << spec << " " << spec2 << "\n";
        if (spec2) {
            f(pos+2), f(pos+3), f(pos+4);
            int ert=pr();
            f(pos+2), f(pos+3), f(pos+4);
            if (ert==x-1 || ert==x+3) {
                s(pos+4);
            }
            if (ert==x+1 || ert==x+3) {
                s(pos+2), s(pos+3);
            } else {
                s(pos+1);
            }
            spec=0, spec2=0;
            pos+=4;
        } else if (spec) {
            f(pos+1), f(pos+3);
            int ert=pr();
            f(pos+1), f(pos+3);
            if (ert==x+2) {
                s(pos+1);
                s(pos+3);
                pos+=3;
            }
            if (ert==x-2) {
                s(pos+2);
                pos+=3;
            }
            if (ert==x) {
                spec2=1;
            }
            spec=0;
        } else {
            if (pos+5>=n) {
                f(pos+1);
                ert=pr();
                f(pos+1);
                if (ert==x+1) {
                    s(pos+1);
                }
                pos++;
            } else {
                f(pos+1), f(pos+2);
                ert=pr();
                f(pos+1), f(pos+2);
                if (ert==x+2) {
                    s(pos+1), s(pos+2);
                    pos+=2;
                }
                if (ert==x-2) {
                    pos+=2;
                }
                if (ert==x) {
                    spec=1;
                }
            }
        }
    }
    swap(v, fix);
    //cout << "vege\n";
    pr();
    return 0;
}