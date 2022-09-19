#include <bits/stdc++.h>

using namespace std;
const int c=200005;

int n, bal, jobb, kezd[c], veg[c], t[c], cnt;
long long ert[c], kov[c][2], ans[c][2];
bool v[c];
vector<int> sz[c][2], alap;
void pb() {
    cnt++;
    kezd[cnt]=bal, veg[cnt]=jobb;
    if (bal==jobb) {
        t[cnt]=3;
    } else if (ert[bal]==ert[jobb]) {
        t[cnt]=2;
    } else {
        t[cnt]=1;
    }
    bal=0, jobb=0;
}
long long calc(long long l, long long r) {
    long long db=r-l+1;
    return db*l+db*(db-1)/2;
}
void solve(int kis, int bal, int jobb, long long sum, int id, int tip, int el) {
    if (jobb<kis) {
        return;
    }
    jobb=max(jobb, bal-1);
    long long ossz=jobb-bal+1, lo=-1, hi=ossz+1, mid, mins, maxs;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        mins=calc(bal, bal+mid-1);
        maxs=calc(jobb-mid+1, jobb);
        if (kis+maxs<sum) {
            lo=mid;
        } else {
            hi=mid;
        }
    }
    if (hi==ossz+1) {
        return;
    }
    int kisdb=hi, nagydb=0, spec=0, add=ossz-hi;
    long long rem=sum-kis-calc(bal, bal+hi-1);
    while (kisdb && rem>0) {
        if (rem>add) {
            rem-=add;
            kisdb--, nagydb++;
        } else {
            spec=bal+kisdb-1+rem;
            rem=0;
            kisdb--;
        }
    }
    long long kozel=kis+rem;
    long long sum2=0;
    if (kozel>ans[id][tip] && (tip==0 || kozel==kis)) {
        ans[id][tip]=kozel;
        kov[id][tip]=el;
        vector<int> x;
        x.push_back(kozel);
        for (int i=bal; i<=bal+kisdb-1; i++) {
            x.push_back(i);
        }
        for (int i=jobb-nagydb+1; i<=jobb; i++) {
            x.push_back(i);
        }
        if (spec) {
            x.push_back(spec);
        }
        sz[id][tip]=x;
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=n; i>=1; i--) {
        cin >> ert[i];
        if (ert[i]) {
            alap.push_back(i);
        }
    }
    for (int x:alap) {
        if (!bal) {
            bal=x, jobb=x;
        } else if (ert[x]<=ert[jobb]) {
            jobb=x;
        } else {
            pb();
            bal=x, jobb=x;
        }
    }
    if (ert[bal]!=ert[jobb]) {
        pb();
    }
    for (int i=0; i<=n; i++) {
        ans[i][0]=-1, ans[i][1]=-1;
    }
    ans[0][1]=n+1;
    for (int i=1; i<=cnt; i++) {
        int un=ans[i-1][0], ue=ans[i-1][1];
        long long sum=ert[veg[i]]-ert[veg[i-1]];
        if (t[i]==2 || t[i]==3 && kezd[i]) {
            if (un>kezd[i]) solve(veg[i]-1, kezd[i]+1, un-1, sum, i, 0, 0);
            solve(veg[i]-1, kezd[i]+1, ue-1, sum-1, i, 0, 1);
        }
        if (t[i]==1 || t[i]==3) {
            if (un>kezd[i]) solve(veg[i], kezd[i]+1, un-1, sum+1, i, 1, 0);
            solve(veg[i], kezd[i]+1, ue-1, sum, i, 1, 1);
        }
    }
    if (bal) {
        int un=ans[cnt][0], ue=ans[cnt][1];
        long long sum=ert[bal]-ert[veg[cnt]];
        cnt++;
        for (int i=bal; i>=0; i--) {
            if (!ert[i]) {
                solve(i, bal+1, un-1, sum, cnt, 1, 0);
                solve(i, bal+1, ue-1, sum-1, cnt, 1, 1);
                if (ans[cnt][1]>=0) {
                    break;
                }
            }
        }
    }
    int pos=(ans[cnt][0]>=0 ? 0 : 1);
    for (int i=cnt; i>=1; i--) {
        for (int x:sz[i][pos]) {
            v[x]=1;
        }
        pos=kov[i][pos];
    }
    for (int i=n; i>=1; i--) {
        cout << v[i];
    }
    return 0;
}