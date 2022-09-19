#include<bits/stdc++.h>

using namespace std;
const int c=10000002, c2=100002, gy=3500;
//const int c=1002, c2=1002, gy=1002;
int prdb[c], cnt[c], t[c2], db[c2], n, k, kk, si, spec, udb, ut;
bool pr[c], nm[c], v[c2], h[c];
vector<int> ans;
vector<int> oszt[c];
int add(int a, int v) {
    int ert=t[a], ans=0;
    for (int x:oszt[ert]) {
        int s=(prdb[x]%2 ? 1 : -1);
        ans+=cnt[x]*s;
        cnt[x]+=v;
    }
    ans=si-ans;
    si+=v;
    return ans;
}
int main()
{
    cin >> n >> k;
    kk=k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        h[t[i]]=1;
    }
    for (int i=2; i<c; i++) {
        pr[i]=1, nm[i]=1;
    }
    for (int i=2; i<c; i++) {
        if (pr[i]) {
            prdb[i]++;
            for (int j=2*i; j<c; j+=i) {
                pr[j]=0, prdb[j]++;
            }
        }
        if (i<gy) {
            for (int j=i*i; j<c; j+=i*i) {
                nm[j]=0;
            }
        }
        if (nm[i]) {
            for (int j=i; j<c; j+=i) {
                if (h[j]) {
                    oszt[j].push_back(i);
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        db[i]+=add(i, 1);
    }
    for (int i=1; i<=n; i++) {
        db[i]+=add(i, -1);
        if (db[i]>=2) {
            spec=i;
        }
        if (db[i]==0) {
            udb++;
        }
        db[i]=0;
    }
    if (!spec || udb>=k) {
        for (int i=1; i<=n; i++) {
            if (k && !add(i, 1)) {
                cout << i << " ";
                k--;
            } else {
                add(i, -1);
            }
        }
        return 0;
    }
    add(spec, 1);
    v[spec]=1, k--;
    for (int i=1; i<=n; i++) {
        if (!v[i] && k && add(i, 0)) {
            v[i]=1, k--;
            ut=i;
        }
    }
    add(spec, -1);
    while (k>0) {
        udb=0;
        for (int i=1; i<=n; i++) {
            if (!v[i]) {
                db[i]+=add(i, 1);
            }
        }
        for (int i=1; i<=n; i++) {
            if (!v[i]) {
                db[i]+=add(i, -1);
                if (!db[i]) {
                    udb++;
                }
                db[i]=0;
            }
        }
        if (udb>=kk) {
            for (int i=1; i<=n; i++) {
                if (!v[i] && kk && !add(i, 1)) {
                    cout << i << " ";
                    kk--;
                }
            }
            return 0;
        }
        int cel=(k+1)/2, sz1=0, sz2=0, pos=n, pos2=1;
        for (int i=1; i<=n; i++) {
            if (!v[i] && add(i, 1)) {
                sz1++;
            }
            if (sz1==cel) {
                pos=i;
                break;
            }
        }
        for (int i=1; i<=pos; i++) {
            if (!v[i]) {
                add(i, -1);
            }
        }
        for (int i=pos; i>=1; i--) {
            if (!v[i] && add(i, 1)) {
                sz2++;
            }
            if (sz2==cel) {
                pos2=i;
                break;
            }
        }
        for (int i=pos; i>=pos2; i--) {
            if (!v[i]) {
                add(i, -1);
            }
        }
        for (int i=pos2; i<=pos; i++) {
            if (!v[i]) {
                db[i]+=add(i, 1);
            }
        }
        for (int i=pos2; i<=pos; i++) {
            if (!v[i]) {
                db[i]+=add(i, -1);
            }
            if (db[i]) {
                v[i]=1;
                k--;
            }
            db[i]=0;
        }
    }
    if (k==-1) {
        v[ut]=0;
    }
    for (int i=1; i<=n; i++) {
        if (v[i]) {
            cout << i << " ";
        }
    }
	return 0;
}