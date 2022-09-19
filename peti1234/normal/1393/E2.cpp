#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
string bal, jobb;
int n, x, y;
long long regi[c], uj[c], mod=1000000007;
vector<int> bs, js;
bool v[c];

unsigned long long t[c][2], po[c], valt=123456789;
unsigned long long calc(int bal, int jobb, int p) {
    return t[jobb][p]-t[bal][p]*po[jobb-bal];
}
bool ua(int p1, int p2, int len) {
    return (calc(p1, p1+len, 0)==calc(p2, p2+len, 1));
}
int solve(int p1, int p2, int len) {
    if (ua(p1, p2, len)) {
        return len;
    }
    int lo=0, hi=len, mid;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        if (ua(p1, p2, mid)) {
            lo=mid;
        } else {
            hi=mid;
        }
    }
    return lo;
}
bool sm(int a, int b) {
    int p1=!a, p2=!b;
    int sb=bal.size(), sj=jobb.size();
    while (p1<sb && p2<sj) {
        int len=min(sb-p1, sj-p2);
        if (a>p1) {
            len=min(len, a-p1);
        }
        if (b>p2) {
            len=min(len, b-p2);
        }
        int ans=solve(p1, p2, len);
        p1+=ans, p2+=ans;
        if (ans!=len) {
            return (bal[p1]<jobb[p2]);
        }
        if (p1==a) {
            p1++;
        }
        if (p2==b) {
            p2++;
        }
    }
    return (p1>=sb);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    regi[0]=1;
    bs.push_back(0);
    po[0]=1;
    for (int i=1; i<c; i++) {
        po[i]=po[i-1]*valt;
    }
    for (int i=1; i<=n; i++) {
        cin >> jobb;
        y=jobb.size();
        for (int i=0; i<y; i++) {
            t[i+1][1]=t[i][1]*valt+(jobb[i]-'a'+1);
        }
        vector<int> kis, nagy;
        v[y-1]=1;
        kis.push_back(y-1);
        for (int i=y-2; i>=0; i--) {
            v[i]=(jobb[i]>jobb[i+1] || (jobb[i]==jobb[i+1] && v[i+1]));
            (v[i] ? kis.push_back(i) : nagy.push_back(i));
        }
        reverse(kis.begin(), kis.end());
        for (auto p:kis) {
            js.push_back(p);
        }
        js.push_back(y);
        for (auto p:nagy) {
            js.push_back(p);
        }

        long long sum=0;
        int pos=0;
        for (auto s:js) {
            while (pos<bs.size() && sm(bs[pos], s)) {
                sum+=regi[bs[pos]];
                sum%=mod;
                pos++;
            }
            uj[s]=sum;
        }
        x=y;
        bs=js;
        bal=jobb;
        for (int i=0; i<=y; i++) {
            t[i][0]=t[i][1], t[i][1]=0;
            regi[i]=uj[i];
            uj[i]=0;
        }
        y=0, js.clear(), jobb.clear();
    }
    long long ans=0;
    for (int i=0; i<=bal.size(); i++) {
        ans+=regi[i];
        ans%=mod;
    }
    cout << ans << "\n";
    return 0;
}