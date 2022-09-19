#include <bits/stdc++.h>

using namespace std;
set<long long> spec;
long long k, k2, n, mod=1e9+7;
map<long long, int> m;

long long calc(int k) {
    long long ans=1, po=16;
    for (int i=1; i<k; i++) {
        ans=ans*po%mod;
        po=po*po%mod;
    }
    return ans;
}
vector<long long> solve(long long id) {
    vector<long long> ans;
    for (int i=0; i<3; i++) ans.push_back(0);
    if (spec.find(id)==spec.end()) {
        int ert=-1;
        if (m.find(id)!=m.end()) {
            ert=m[id];
        }
        int level=0;
        long long id2=id;
        while (id2<k2) {
            id2*=2;
            level++;
        }
        long long s=calc(level);
        if (ert==-1) {
            ans[0]=ans[1]=ans[2]=2*s%mod;
        } else {
            ans[ert]=s;
        }
        /*cout << "ures " << id << "\n";
        for (auto x:ans) {
            cout << x << " ";
        }
        cout << "\n";*/
        return ans;
    }
    vector<long long> bal=solve(2*id), jobb=solve(2*id+1);
    int ert=-1;
    if (m.find(id)!=m.end()) {
        ert=m[id];
    }
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                if (k!=i && k!=j) {
                    ans[k]+=bal[i]*jobb[j]%mod;
                    ans[k]%=mod;
                }
            }
        }
    }
    /*cout << "kezd " << id << " " << ert << "\n";
    for (auto x:ans) {
        cout << x << " ";
    }
    cout << "\n";*/
    for (int i=0; i<3; i++) {
        if (ert==-1) {
            ans[i]=2*ans[i]%mod;
        } else if (i!=ert) {
            ans[i]=0;
        }
    }
    /*cout << "fontos " << id << "\n";
    for (auto x:ans) {
        cout << x << " ";
    }
    cout << "\n";*/
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> k >> n;
    k2=1;
    for (int i=1; i<=k; i++) {
        k2*=2;
    }
    for (int i=1; i<=n; i++) {
        long long x;
        string s;
        cin >> x >> s;
        int ert=(s=="red" || s=="orange" ? 0 : s=="white" || s=="yellow" ? 1 : 2);
        m[x]=ert;
        x/=2;
        while (x>=1) {
            spec.insert(x);
            x/=2;
        }
    }
    vector<long long> sz=solve(1);
    cout << (sz[0]+sz[1]+sz[2])%mod;
    return 0;
}
/*
3
2
5 orange
2 white
*/