#include <bits/stdc++.h>

using namespace std;
const int c=(1<<19);
long long n, q, sum, kezd[c], veg[c], val[c], prob[c], mod=998244353;
set<int> s;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans*=a;
            ans%=mod;
        }
        p/=2;
        a*=a;
        a%=mod;
    }
    return ans;
}

pair<long long, long long> calc(int a, int l, int r) {
    if (kezd[a]>r || veg[a]<l) {
        return {0, 1};
    }
    if (l<=kezd[a] && veg[a]<=r) {
        return {prob[a], val[a]};
    }
    pair<long long, long long> x=calc(2*a, l, r), y=calc(2*a+1, l, r);
    return {(x.first*y.second+y.first)%mod, x.second*y.second%mod};
}

long long calc(int l, int r) {
    return calc(1, l, r-1).first;
}
void init(int a) {
    int po=1;
    while (po<=n) {
        po*=2;
    }
    for (int i=po; i<2*po; i++) {
        kezd[i]=i-po+1, veg[i]=i-po+1;
        if (i-po<n) {
            long long x;
            cin >> x;
            prob[i]=100*oszt(x)%mod;
            val[i]=prob[i];
        }

    }
    for (int i=po-1; i>=1; i--) {
        kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
        val[i]=val[i]=val[2*i]*val[2*i+1]%mod;
        prob[i]=(prob[2*i]*val[2*i+1]+prob[2*i+1])%mod;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    init(n);
    s.insert(1), s.insert(n+1);
    sum=calc(1, n+1);
    for (int i=1; i<=q; i++) {
        int x;
        cin >> x;
        if (s.find(x)!=s.end()) {
            auto it=s.find(x);
            int a, b;
            it--, a=*it, it++, it++, b=*it;
            sum-=calc(a, x), sum-=calc(x, b), sum+=calc(a, b);
            s.erase(x);
        } else {
            s.insert(x);
            auto it=s.find(x);
            int a, b;
            it--, a=*it, it++, it++, b=*it;
            sum+=calc(a, x), sum+=calc(x, b), sum-=calc(a, b);
        }
        sum=(sum+10*mod)%mod;
        cout << sum << "\n";
    }
    return 0;
}
/*
2 0
50 50
*/