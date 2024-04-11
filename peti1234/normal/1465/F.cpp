#include <bits/stdc++.h>

using namespace std;
const int c=1000002;
long long ans, sum, mod=1e9+7;
int w, n, t[c], db[c], cnt;
bool v[c];
void dfs(int a) {
    if (v[a]) {
        return;
    }
    v[a]=true;
    cnt++;
    dfs(t[a]);
}
void cl() {
    while(db[1]>db[2]) {
        db[1]-=2, db[2]++, sum++;
    }
    sum+=max(db[1], db[2]);
}
void t2() {
    if (db[2]) {
        db[2]--;
    } else {
        db[1]-=2;
        sum++;
    }
}
void t4() {
    sum+=db[4];
    db[1]+=db[4];
}
bool spec;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    for (int i=1; i<=w; i++) {
        cin >> n, ans=1, sum=0;
        for (int i=3; i<=n; i+=3) {
            ans%=mod, ans*=3;
        }
        db[4]=0;
        for (int i=1; i<=n; i++) {
            v[i]=0, db[i]=0;
            cin >> t[i];
        }
        for (int i=1; i<=n; i++) {
            if (!v[i]) {
                cnt=0;
                dfs(i);
                db[cnt]++;
            }
        }
        for (int i=n; i>=5; i--) {
            while(db[i]) {
                sum++, db[i]--, db[i-3]++;
            }
        }
        if (n%3==0) {
            t4();
            cl();
        }
        if (n%3==2) {
            ans*=2;
            t4();
            t2();
            cl();
        }
        if (n%3==1) {
            ans/=3, ans*=4;
            if (db[4] && db[1]+db[4]>=db[2]) {
                db[4]--;
                t4();
                cl();
            } else {
                t4();
                if (db[1]==1 && db[2]==0) {
                    sum++;
                } else {
                    t2();
                    t2();
                    cl();
                }
            }
        }
        cout << ans%mod << " " << sum << "\n";
    }
    return 0;
}