#include<bits/stdc++.h>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
class BIT {
    private:
    int n;
    vector<int> v;
    public:
    BIT() {
        n=0;
    }
    BIT(int n) {
        this->n=n;
        v.assign(n+7,0);
    }
    void update(int x) {
        if (x<1 || x>n) return;
        for (;x<=n;x+=x&-x) v[x]++;
    }
    int get(int x) const {
        if (x<1 || x>n) return (0);
        int ret=0;
        for (;x>=1;x&=x-1) ret+=v[x];
        return (ret);
    }
};
map<int,int> mp;
int a[MAX],c[MAX],n;
BIT bit;
void init() {
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n) {
        mp[a[i]]++;
        c[i]=mp[a[i]];
    }
    bit=BIT(n);
}
void process() {
    mp.clear();
    long long res=0;
    FORD(i,n,1) {
        res+=bit.get(c[i]-1);
        mp[a[i]]++;
        bit.update(mp[a[i]]);
    }
    cout<<res<<endl;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    process();
}