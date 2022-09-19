#include <bits/stdc++.h>

using namespace std;
const int c=35005;
long long n, l[c], r[c];
long long solve(long long ert) {
    long long ans=0, lcs=0, rcs=0;
    priority_queue<long long> bal;
    priority_queue<long long, vector<long long>, greater<long long> > jobb;
    for (int i=1; i<=n; i++) {
        bal.push(ert);
        jobb.push(ert);
    }
    for (long long i=1; i<=n; i++) {
        lcs+=l[i], rcs+=r[i];
        long long bt=bal.top()+lcs, jt=jobb.top()+rcs;
        if (bt>0) {
            ans+=bt;
            bal.pop();
            jobb.push(bt-rcs);
            bal.push(-lcs), bal.push(-lcs);
        } else if (jt<0) {
            ans-=jt;
            jobb.pop();
            bal.push(jt-lcs);
            jobb.push(-rcs), jobb.push(-rcs);
        } else {
            bal.push(-lcs), jobb.push(-rcs);
        }

    }
    while (bal.size()>0 && bal.top()+lcs>ert) {
        ans+=bal.top()+lcs-ert;
        bal.pop();
    }
    while (jobb.size()>0 && jobb.top()+rcs<ert) {
        ans+=ert-jobb.top()-rcs;
        jobb.pop();
    }
    return ans;

}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        l[i]=a-c, r[i]=a-b;
    }
    long long lo=-c*c, hi=c*c, mid;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        if (solve(mid)<solve(mid+1)) {
            hi=mid;
        } else {
            lo=mid;
        }
    }
    cout << solve(hi) << "\n";
    return 0;
}