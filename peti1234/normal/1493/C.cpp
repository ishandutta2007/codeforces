#include <bits/stdc++.h>

using namespace std;
const int c=27, kk=100002;
int w, n, k, db[27], t[kk], p[kk], sum, pos;
string s;
int valt(char c) {
    return c-'a';
}
char vvalt(int a) {
    char x='a';
    return x+a;
}
void vege() {
    /*
    if (w==4014) {
        return;;
    }
    */
    for (int i=1; i<=n; i++) {
        cout << vvalt(p[i]);
    }
    cout << "\n";
}
void lk(int a) {
    for (int i=a; i<=n; i++) {
        for (int j=0; j<c; j++) {
            if (db[j]) {
                p[i]=j;
                db[j]--;
                break;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    for (int i=1; i<=w; i++) {
        cin >> n >> k;
        cin >> s;
        /*if (w==4014 && i==1000) {
            cout << "baj_" << n << "_" << k << "_" << s << endl;
        }*/
        if (n%k) {
            cout << -1 << "\n";
            continue;
        }
        for (int i=0; i<c; i++) {
            db[i]=0;
        }
        sum=0, pos=0;
        for (int i=1; i<=n; i++) {
            t[i]=valt(s[i-1]), p[i]=0;
        }
        for (int i=1; i<=n; i++) {
            if (!db[t[i]]) {
                if (sum==n) {
                    pos=i;
                    break;
                }
                sum+=k;
                db[t[i]]+=k;
            }
            p[i]=t[i];
            db[t[i]]--;
        }
        if (!pos) {
            vege();
            continue;
        }
        bool jo=0;
        for (int i=0; i<c; i++) {
            if (db[i]>0 && i>t[pos]) {
                p[pos]=i;
                db[i]--;
                lk(pos+1);
                vege();
                jo=1;
                break;
            }
        }
        if (jo) {
            continue;
        }
        for (int i=pos-1; ; i--) {
            db[p[i]]++;
            if (db[p[i]]==k) {
                db[p[i]]=0;
                sum-=k;
                pos=i;
                break;
            }
            for (int j=p[i]+1; j<c; j++) {
                if (db[j]>0) {
                    p[i]=j;
                    db[j]--;
                    lk(i+1);
                    vege();
                    jo=1;
                }
            }
            if (jo) {
                break;
            }
        }
        if (jo) {
            continue;
        }
        //cout << "most sincs vege " << pos << "\n";
        for (int i=pos; ; i--) {
            if (t[i]!=25) {
                if (i!=pos) {
                    db[t[i]]++;
                    if (db[t[i]]==k) {
                        db[t[i]]=0;
                        db[t[0]]+=k;
                    }
                }
                sum+=k;
                if (db[t[i]+1]) {
                    db[0]+=k;
                } else {
                    db[t[i]+1]+=k;
                }
                p[i]=t[i]+1;
                db[p[i]]--;
                lk(i+1);
                break;
            }
        }
        vege();
    }
    return 0;
}
/*
1
20 5
izzzzzozzzzzznjskzcg
*/